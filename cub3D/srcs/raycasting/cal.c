/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:27:56 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/01 15:46:47 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc(t_window *window)
{
	t_map	*info;
	char	**worldmap;

	info = &(window->info->map_info);
	worldmap = window->info->map;
	//FLOOR CASTING
	for(int y = 0; y < HEIGHT; y++)
	{
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float rayDirX0 = info->dir_x - info->plane_x;
		float rayDirY0 = info->dir_y - info->plane_y;
		float rayDirX1 = info->dir_x + info->plane_x;
		float rayDirY1 = info->dir_y + info->plane_y;

		// Current y position compared to the center of the screen (the horizon)
		int p = y - HEIGHT / 2;

		// Vertical position of the camera.
		float posZ = 0.5 * HEIGHT;

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;

		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WIDTH;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WIDTH;

		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		float floorX = info->player_x + rowDistance * rayDirX0;
		float floorY = info->player_y + rowDistance * rayDirY0;

		for(int x = 0; x < WIDTH; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			// get the texture coordinate from the fractional part
			int tx = (int)(TEXWIDTH * (floorX - cellX)) & (TEXWIDTH - 1);
			int ty = (int)(TEXHEIGHT * (floorY - cellY)) & (TEXHEIGHT - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			// floor
			window->buf[y][x] = window->info->text->f_color;
			// celling
			window->buf[HEIGHT - y - 1][x] = window->info->text->c_color;
		}
	}
	//WALL CASTING

	for(int x = 0; x < WIDTH; x++)
	{
		double cameraX = 2 * x / (double)WIDTH - 1;
		double rayDirX = info->dir_x + info->plane_x * cameraX;
		double rayDirY = info->dir_y + info->plane_y * cameraX;
		
		int mapX = (int)info->player_x;
		int mapY = (int)info->player_y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->player_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->player_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->player_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->player_y) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldmap[mapY][mapX] == '1')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - info->player_x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->player_y + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(HEIGHT / perpWallDist);
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		// texturing calculations texNum으로 벽면 이미지 바꾸는중
		int texNum = 1;
		if (side == 1)
			texNum = 2;

		double wallX;
		if (side == 0)
			wallX = info->player_y + perpWallDist * rayDirY;
		else
			wallX = info->player_x + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)TEXWIDTH);
		if (side == 0 && rayDirX > 0)
			texX = TEXWIDTH - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = TEXWIDTH - texX - 1;

		double step = 1.0 * TEXWIDTH / lineHeight;

		// Starting texture coordinate
		double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;

		for (int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (TEXHEIGHT - 1);
			texPos += step;

			int color = window->texture[texNum][TEXHEIGHT * texY + texX];

			window->buf[y][x] = color;
		}
	}
}

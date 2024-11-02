/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:27:56 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/02 15:32:33 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	floor_casting(t_window *window, t_map *info)
{
	int		y;
	t_floor	f;

	y = -1;
	while (++y < HEIGHT)
	{		
		f.raydir_x0 = info->dir_x - info->plane_x;
		f.raydir_y0 = info->dir_y - info->plane_y;
		f.raydir_x1 = info->dir_x + info->plane_x;
		f.raydir_x1 = info->dir_y + info->plane_y;
		f.p = y - HEIGHT / 2;
		f.pos_z = 0.5 * HEIGHT;
		f.row_distance = f.pos_z / f.p;
		f.floorstep_x = f.row_distance * (f.raydir_x1 - f.raydir_x0) / WIDTH;
		f.floorstep_y = f.row_distance * (f.raydir_y1 - f.raydir_y0) / WIDTH;
		f.floor_x = info->player_x + f.row_distance * f.raydir_x0;
		f.floor_y = info->player_y + f.row_distance * f.raydir_y0;
		save_floor(window, &f, y);
	}
}

void	init_step(t_raycast *r, t_map *info)
{
	r->map_x = (int)info->player_x;
	r->map_y = (int)info->player_y;
	r->deltadist_x = fabs(1 / r->raydir_x);
	r->deltadist_y = fabs(1 / r->raydir_y);
	r->hit = 0; //was there a wall hit?
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (info->player_x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - info->player_x) * r->deltadist_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (info->player_y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - info->player_y) * r->deltadist_y;
	}
}

void	dda(t_raycast *r, char **worldmap)
{
	while (r->hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		//Check if ray has hit a wall
		if (worldmap[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	calc(t_window *window)
{
	t_map		*info;
	char		**worldmap;
	int			x;
	t_raycast	r;

	info = &(window->info->map_info);
	worldmap = window->info->map;
	floor_casting(window, info);
	x = -1;
	while (++x < WIDTH)
	{
		r.camera_x = 2 * x / (double)WIDTH - 1;
		r.raydir_x = info->dir_x + info->plane_x * r.camera_x;
		r.raydir_y = info->dir_y + info->plane_y * r.camera_x;
		init_step(&r, info);
		dda(&r, worldmap);
		if (r.side == 0)
			r.perpwalldist = (r.map_x - info->player_x
					+ (1 - r.step_x) / 2) / r.raydir_x;
		else
			r.perpwalldist = (r.map_y - info->player_y
					+ (1 - r.step_y) / 2) / r.raydir_y;
		save_wall(window, info, &r, x);
	}
}

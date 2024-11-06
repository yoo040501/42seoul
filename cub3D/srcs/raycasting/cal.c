/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:27:56 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/06 15:34:00 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_cell_floor(t_window *window)
{
	int		y;
	int		x;

	y = -1;
	while (++y < HEIGHT / 2)
	{		
		x = -1;
		while (++x < WIDTH)
		{
				window->buf[y][x] = window->info->text->c_color;
				window->buf[HEIGHT - y - 1][x] = window->info->text->f_color;
		}
	}
}

void	init_step(t_raycast *r, t_map *info)
{
	r->map_x = (int)info->player_x;
	r->map_y = (int)info->player_y;
	r->deltadist_x = fabs(1 / r->raydir_x);
	r->deltadist_y = fabs(1 / r->raydir_y);
	r->hit = 0;
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
	init_cell_floor(window);
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

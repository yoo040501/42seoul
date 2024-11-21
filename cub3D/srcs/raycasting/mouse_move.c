/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:35:56 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 14:13:15 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_right(t_map *map, double rot_speed)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = map->dir_x;
	map->dir_x = map->dir_x * cos(rot_speed)
		- map->dir_y * sin(rot_speed);
	map->dir_y = olddir_x * sin(rot_speed)
		+ map->dir_y * cos(rot_speed);
	oldplane_x = map->plane_x;
	map->plane_x = map->plane_x * cos(rot_speed)
		- map->plane_y * sin(rot_speed);
	map->plane_y = oldplane_x * sin(rot_speed)
		+ map->plane_y * cos(rot_speed);
}

static void	move_left(t_map *map, double rot_speed)
{
	double	olddir_x;
	double	oldplane_x;	

	olddir_x = map->dir_x;
	map->dir_x = map->dir_x * cos(-rot_speed)
		- map->dir_y * sin(-rot_speed);
	map->dir_y = olddir_x * sin(-rot_speed)
		+ map->dir_y * cos(-rot_speed);
	oldplane_x = map->plane_x;
	map->plane_x = map->plane_x * cos(-rot_speed)
		- map->plane_y * sin(-rot_speed);
	map->plane_y = oldplane_x * sin(-rot_speed)
		+ map->plane_y * cos(-rot_speed);
}

static void	mouse_updown(t_window *window)
{
	if (window->key_flag.mouse_d)
	{
		if (window->camera_height > 0)
			window->camera_height -= 0.02;
	}
	if (window->key_flag.mouse_u)
	{
		if (window->camera_height < 1.0)
			window->camera_height += 0.02;
	}
}

void	mouse_move(t_window *window)
{
	double	rot_speed;
	t_map	*map;

	rot_speed = window->rot_speed;
	map = &window->info->map_info;
	if (window->key_flag.mouse_l == 1)
		move_left(map, rot_speed);
	if (window->key_flag.mouse_r == 1)
		move_right(map, rot_speed);
	if (window->key_flag.mouse_d || window->key_flag.mouse_u)
		mouse_updown(window);
}

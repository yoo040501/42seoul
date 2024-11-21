/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:07:56 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/14 19:26:40 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	key_updown(t_window *window)
{
	if (window->key_flag.key_down)
	{
		if (window->camera_height > 0)
			window->camera_height -= 0.02;
	}
	if (window->key_flag.key_up)
	{
		if (window->camera_height < 1.0)
			window->camera_height += 0.02;
	}
}

void	key_rotate_r(t_window *window, t_map *map)
{
	double	olddir_x;
	double	oldplane_x;

	if (window->key_flag.key_r)
	{
		olddir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(window->rot_speed)
			- map->dir_y * sin(window->rot_speed);
		map->dir_y = olddir_x * sin(window->rot_speed)
			+ map->dir_y * cos(window->rot_speed);
		oldplane_x = map->plane_x;
		map->plane_x = map->plane_x * cos(window->rot_speed)
			- map->plane_y * sin(window->rot_speed);
		map->plane_y = oldplane_x * sin(window->rot_speed)
			+ map->plane_y * cos(window->rot_speed);
	}
}

void	key_rotate_l(t_window *window, t_map *map)
{
	double	olddir_x;
	double	oldplane_x;

	if (window->key_flag.key_l)
	{
		olddir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(-window->rot_speed)
			- map->dir_y * sin(-window->rot_speed);
		map->dir_y = olddir_x * sin(-window->rot_speed)
			+ map->dir_y * cos(-window->rot_speed);
		oldplane_x = map->plane_x;
		map->plane_x = map->plane_x * cos(-window->rot_speed)
			- map->plane_y * sin(-window->rot_speed);
		map->plane_y = oldplane_x * sin(-window->rot_speed)
			+ map->plane_y * cos(-window->rot_speed);
	}
}

void	key_move_rl(t_window *window, t_map *map, char **worldmap)
{
	if (window->key_flag.key_a)
	{
		if (worldmap[(int)(map->player_y - map->dir_x
				* (window->move_speed + 0.001))]
		[(int)(map->player_x)] == '0')
			map->player_y -= map->dir_x * window->move_speed;
		if (worldmap[(int)(map->player_y)]
		[(int)(map->player_x + map->dir_y
				* (window->move_speed + 0.001))] == '0')
			map->player_x += map->dir_y * window->move_speed;
	}
	if (window->key_flag.key_d)
	{
		if (worldmap[(int)(map->player_y + map->dir_x
				* (window->move_speed + 0.001))]
		[(int)(map->player_x)] == '0')
			map->player_y += map->dir_x * window->move_speed;
		if (worldmap[(int)(map->player_y)]
		[(int)(map->player_x - map->dir_y
				* (window->move_speed + 0.001))] == '0')
			map->player_x -= map->dir_y * window->move_speed;
	}
}

void	key_move_updown(t_window *window, t_map *map, char **worldmap)
{
	if (window->key_flag.key_w)
	{
		if (worldmap[(int)(map->player_y + map->dir_y
				* (window->move_speed + 0.001))]
		[(int)(map->player_x)] == '0')
			map->player_y += map->dir_y * window->move_speed;
		if (worldmap[(int)(map->player_y)]
		[(int)(map->player_x + map->dir_x
				* (window->move_speed +0.001))] == '0')
			map->player_x += map->dir_x * window->move_speed;
	}
	if (window->key_flag.key_s)
	{
		if (worldmap[(int)(map->player_y - map->dir_y
				* (window->move_speed + 0.001))]
		[(int)(map->player_x)] == '0')
			map->player_y -= map->dir_y * window->move_speed;
		if (worldmap[(int)(map->player_y)]
		[(int)(map->player_x - map->dir_x
				* (window->move_speed + 0.001))] == '0')
			map->player_x -= map->dir_x * window->move_speed;
	}
}

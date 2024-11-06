/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:07:56 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/06 15:16:18 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (worldmap[(int)(map->player_y - map->dir_x * (window->move_speed + 0.001))]
		[(int)(map->player_x)] == '0')
		{
			map->player_y -= map->dir_x * window->move_speed;
			//printf("%f %f\n", map->player_y, map->player_x );
		}
		if (worldmap[(int)(map->player_y)]
		[(int)(map->player_x + map->dir_y * (window->move_speed + 0.001))] == '0')
		{
			map->player_x += map->dir_y * window->move_speed;
			//printf("%f %f\n", map->player_y, map->player_x );
		}
	}
	if (window->key_flag.key_d)
	{
		if (worldmap[(int)(map->player_y + map->dir_x * (window->move_speed + 0.001))]
		[(int)(map->player_x)] == '0')
		{
			map->player_y += map->dir_x * window->move_speed;
			//printf("%f %f\n", map->player_y, map->player_x );
		}
		if (worldmap[(int)(map->player_y)]
		[(int)(map->player_x - map->dir_y * (window->move_speed + 0.001))] == '0')
		{
			map->player_x -= map->dir_y * window->move_speed;
			//printf("%f %f\n", map->player_y, map->player_x );
		}
	}
}

void	key_move_updown(t_window *window, t_map *map, char **worldmap)
{
	if (window->key_flag.key_w)
	{
		if (worldmap[(int)(map->player_y + map->dir_y * (window->move_speed + 0.001))]
		[(int)(map->player_x)] == '0')
		{
			map->player_y += map->dir_y * window->move_speed;
			//printf("%f %f\n", map->player_y, map->player_x );
		}
		if (worldmap[(int)(map->player_y)]
		[(int)(map->player_x + map->dir_x * (window->move_speed +0.001))] == '0')
		{
			map->player_x += map->dir_x * window->move_speed;
		//	printf("%f %f\n", map->player_y, map->player_x );
		}
	}
	if (window->key_flag.key_s)
	{
		if (worldmap[(int)(map->player_y - map->dir_y * (window->move_speed + 0.001))]
		[(int)(map->player_x)] == '0')
		{
			map->player_y -= map->dir_y * window->move_speed;
		//	printf("%f %f\n", map->player_y, map->player_x );
		}
		if (worldmap[(int)(map->player_y)]
		[(int)(map->player_x - map->dir_x * (window->move_speed + 0.001))] == '0')
		{
			map->player_x -= map->dir_x * window->move_speed;
			//printf("%f %f\n", map->player_y, map->player_x );
		}
	}
}

void	key_space(t_window *window)
{
	if (window->key_flag.key_space)
	{
		if (window->camera_height < 1.0)
			window->camera_height += 0.01;
	}
	else
	{
		if (window->camera_height > 0.5)
			window->camera_height -= 0.01;
	}
}
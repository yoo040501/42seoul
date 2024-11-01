/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:28:12 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/01 15:55:13 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		key_press(int key, t_window *window)
{
	if (key == KEY_ESCAPE)
		closed(window);
	else if (key == KEY_W)
		window->key_w = 1;
	else if (key == KEY_A)
		window->key_a = 1;
	else if (key == KEY_S)
		window->key_s = 1;
	else if (key == KEY_D)
		window->key_d = 1;
	else if (key == KEY_RIGHT)
		window->key_r = 1;
	else if (key == KEY_LEFT)
		window->key_l = 1;
	return (0);
}

int		key_release(int key, t_window *window)
{
	if (key == KEY_ESCAPE)
		closed(window);
	else if (key == KEY_W)
		window->key_w = 0;
	else if (key == KEY_A)
		window->key_a = 0;
	else if (key == KEY_S)
		window->key_s = 0;
	else if (key == KEY_D)
		window->key_d = 0;
	else if (key == KEY_RIGHT)
		window->key_r = 0;
	else if (key == KEY_LEFT)
		window->key_l = 0;
	return (0);
}

void	key_move(t_window *window)
{
	t_map	*map;
	char	**worldmap;

	map = &window->info->map_info;
	worldmap = window->info->map;
	if (window->key_w)
	{
		if (worldmap[(int)(map->player_y + map->dir_y * window->move_speed)][(int)(map->player_x)] == '0')
			map->player_y += map->dir_y * window->move_speed;
		if (worldmap[(int)(map->player_y)][(int)(map->player_x + map->dir_x * window->move_speed)] == '0')
			map->player_x += map->dir_x * window->move_speed;
	}
	if (window->key_a)
	{
		if (worldmap[(int)(map->player_y + map->dir_x * window->move_speed)][(int)(map->player_x)] == '0')
			map->player_y += map->dir_x * window->move_speed;
		if (worldmap[(int)(map->player_y)][(int)(map->player_x + map->dir_y * window->move_speed)] == '0')
			map->player_x -= map->dir_y * window->move_speed;
	}
	if (window->key_s)
	{
		if (worldmap[(int)(map->player_y - map->dir_y * window->move_speed)][(int)(map->player_x)] == '0')
			map->player_y -= map->dir_y * window->move_speed;
		if (worldmap[(int)(map->player_y)][(int)(map->player_x - map->dir_x * window->move_speed)] == '0')
			map->player_x -= map->dir_x * window->move_speed;
	}
	if (window->key_d)
	{
		if (worldmap[(int)(map->player_y + map->dir_x * window->move_speed)][(int)(map->player_x)] == '0')
			map->player_y -= map->dir_x * window->move_speed;
		if (worldmap[(int)(map->player_y)][(int)(map->player_x + map->dir_y * window->move_speed)] == '0')
			map->player_x += map->dir_y * window->move_speed;
	}
	//rotate to the right
	if (window->key_r)
	{
		double olddir_X = map->dir_x;
		map->dir_x = map->dir_x * cos(-window->rot_speed) - map->dir_y * sin(-window->rot_speed);
		map->dir_y = olddir_X * sin(-window->rot_speed) + map->dir_y * cos(-window->rot_speed);
		double oldPlaneX = map->plane_x;
		map->plane_x = map->plane_x * cos(-window->rot_speed) - map->plane_y * sin(-window->rot_speed);
		map->plane_y = oldPlaneX * sin(-window->rot_speed) + map->plane_y * cos(-window->rot_speed);
	}
	//rotate to the left
	if (window->key_l)
	{
		double olddir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(window->rot_speed) - map->dir_y * sin(window->rot_speed);
		map->dir_y = olddir_x * sin(window->rot_speed) + map->dir_y * cos(window->rot_speed);
		double oldPlaneX = map->plane_x;
		map->plane_x = map->plane_x * cos(window->rot_speed) - map->plane_y * sin(window->rot_speed);
		map->plane_y = oldPlaneX * sin(window->rot_speed) + map->plane_y * cos(window->rot_speed);
	}
}
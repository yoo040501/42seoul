/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:28:12 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/06 15:17:19 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int key, t_window *window)
{
	if (key == KEY_ESCAPE)
		closed(window);
	else if (key == KEY_W)
		window->key_flag.key_w = 1;
	else if (key == KEY_A)
		window->key_flag.key_a = 1;
	else if (key == KEY_S)
		window->key_flag.key_s = 1;
	else if (key == KEY_D)
		window->key_flag.key_d = 1;
	else if (key == KEY_RIGHT)
		window->key_flag.key_r = 1;
	else if (key == KEY_LEFT)
		window->key_flag.key_l = 1;
	else if (key == KEY_SPACE)
		window->key_flag.key_space = 1;
	return (0);
}

int	key_release(int key, t_window *window)
{
	if (key == KEY_ESCAPE)
		closed(window);
	else if (key == KEY_W)
		window->key_flag.key_w = 0;
	else if (key == KEY_A)
		window->key_flag.key_a = 0;
	else if (key == KEY_S)
		window->key_flag.key_s = 0;
	else if (key == KEY_D)
		window->key_flag.key_d = 0;
	else if (key == KEY_RIGHT)
		window->key_flag.key_r = 0;
	else if (key == KEY_LEFT)
		window->key_flag.key_l = 0;
	else if (key == KEY_SPACE)
		window->key_flag.key_space = 0;
	return (0);
}

void	key_move(t_window *window)
{
	t_map	*map;
	char	**worldmap;

	map = &window->info->map_info;
	worldmap = window->info->map;
	key_move_updown(window, map, worldmap);
	key_move_rl(window, map, worldmap);
	key_rotate_r(window, map);
	key_rotate_l(window, map);
	key_space(window);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:28:12 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/14 19:23:58 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
	else if (key == KEY_DOWN)
		window->key_flag.key_down = 1;
	else if (key == KEY_UP)
		window->key_flag.key_up = 1;
	else if (key == KEY_NUM_ONE)
		window->key_flag.key_mode = 1;
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
	else if (key == KEY_DOWN)
		window->key_flag.key_down = 0;
	else if (key == KEY_UP)
		window->key_flag.key_up = 0;
	else if (key == KEY_NUM_ONE)
		window->key_flag.key_mode = 0;
	else if (key == KEY_NUM_TWO)
		window->key_flag.key_mode = 2;
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
	key_updown(window);
}

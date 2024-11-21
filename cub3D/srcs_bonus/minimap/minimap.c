/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:53:38 by ycho2             #+#    #+#             */
/*   Updated: 2024/11/14 19:39:55 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	color_minimap(char tile, t_window *window, int map_y, int map_x)
{
	int	tile_color;
	int	buf_x;
	int	buf_y;
	int	x;
	int	y;

	if (window->info->map_height > window->info->map_width)
		window->minimap_grid = 400 / window->info->map_height;
	else
		window->minimap_grid = 400 / window->info->map_width;
	buf_x = map_x * window->minimap_grid;
	buf_y = map_y * window->minimap_grid;
	if (tile == '1' || tile == ' ')
		tile_color = 0xffffff;
	else
		tile_color = 0x000000;
	y = -1;
	while (++y < window->minimap_grid)
	{
		x = -1;
		while (++x < window->minimap_grid)
			window->buf[buf_y + y][buf_x + x] = tile_color;
	}
}

void	minimap(t_window *window)
{
	t_map	*map_info;
	char	**map;
	int		map_x;
	int		map_y;
	int		end_flag;

	map_info = &(window->info->map_info);
	map = window->info->map;
	map_y = -1;
	while (++map_y < window->info->map_height)
	{
		map_x = -1;
		end_flag = 0;
		while (++map_x < window->info->map_width)
		{
			if (map[map_y][map_x] == '\0')
				end_flag = 1;
			if (end_flag == 1)
				color_minimap('1', window, map_y, map_x);
			else
				color_minimap(map[map_y][map_x], window, map_y, map_x);
		}
	}
	minimap_player(window);
}

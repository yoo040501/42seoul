/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:38:27 by ycho2             #+#    #+#             */
/*   Updated: 2024/11/14 19:39:51 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	draw_triangle(t_player *player_info, t_window *window);
static void	player_util(t_player *player_info);
static void	fill_triangle(t_player *player_info, t_window *window);
static int	is_inside(t_player *player_info, int y, int x);

void	minimap_player(t_window *window)
{
	t_map		map_info;
	t_player	player_info;

	map_info = window->info->map_info;
	player_info.theta = atan2(map_info.dir_y, map_info.dir_x) - atan2(-1, 0);
	player_info.cos_theta = cos(player_info.theta);
	player_info.sin_theta = sin(player_info.theta);
	draw_triangle(&player_info, window);
}

static void	draw_triangle(t_player *player_info, t_window *window)
{
	const int		half_grid = window->minimap_grid / 2;
	const double	cos = player_info->cos_theta;
	const double	sin = player_info->sin_theta;
	t_map			map_info;

	map_info = window->info->map_info;
	player_info->triangle[0][0] = -half_grid * sin + half_grid * cos
		+map_info.player_y * window->minimap_grid;
	player_info->triangle[0][1] = -half_grid * cos - half_grid * sin
		+map_info.player_x * window->minimap_grid;
	player_info->triangle[1][0] = half_grid * sin + half_grid * cos
		+map_info.player_y * window->minimap_grid;
	player_info->triangle[1][1] = half_grid * cos - half_grid * sin
		+map_info.player_x * window->minimap_grid;
	player_info->triangle[2][0] = -window->minimap_grid * cos
		+map_info.player_y * window->minimap_grid;
	player_info->triangle[2][1] = window->minimap_grid * sin
		+map_info.player_x * window->minimap_grid;
	player_util(player_info);
	fill_triangle(player_info, window);
}

static void	player_util(t_player *player_info)
{
	const	int	(*triangle)[2] = player_info->triangle;
	int			i;
	int			j;

	player_info->max_y = ft_max(triangle[0][0], triangle[1][0]);
	player_info->max_y = ft_max(player_info->max_y, triangle[2][0]);
	player_info->max_x = ft_max(triangle[0][1], triangle[1][1]);
	player_info->max_x = ft_max(player_info->max_x, triangle[2][1]);
	player_info->min_y = ft_min(triangle[0][0], triangle[1][0]);
	player_info->min_y = ft_min(player_info->min_y, triangle[2][0]);
	player_info->min_x = ft_min(triangle[0][1], triangle[1][1]);
	player_info->min_x = ft_min(player_info->min_x, triangle[2][1]);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 2)
			player_info->line_vec[i][j]
				= triangle[(i + 1) % 3][j] - triangle[i][j];
	}
}

static void	fill_triangle(t_player *player_info, t_window *window)
{
	int		x;
	int		y;

	y = player_info->min_y - 1;
	while (++y <= player_info->max_y)
	{
		x = player_info->min_x - 1;
		while (++x <= player_info->max_x)
		{
			if (is_inside(player_info, y, x) > 0)
				window->buf[y][x] = 0xff0000;
		}
	}
}

static int	is_inside(t_player *player_info, int y, int x)
{
	const	int	(*triangle)[2] = player_info->triangle;
	int			i;
	int			vec_y;
	int			vec_x;
	int			cross;

	i = -1;
	while (++i < 3)
	{
		vec_y = y - triangle[i][0];
		vec_x = x - triangle[i][1];
		cross = player_info->line_vec[i][1] * vec_y
			- player_info->line_vec[i][0] * vec_x;
		if (cross > 0)
			return (-1);
	}
	return (1);
}

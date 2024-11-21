/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:44:28 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/12 13:28:57 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	is_closed(t_info *info, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '1' && map[y][x] != ' ')
			{
				if (y == 0 || y == info->map_height - 1
					|| x == 0 || x == info->map_width - 1
					|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '
					|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '
					|| map[y][x + 1] == 0 || map[y + 1][x] == 0)
					print_error("Error: must be surrouned wall\n");
			}
		}
	}
}

void	get_player_info(t_info *info, int i, int j, int dir)
{
	info->map_info.player_y = i + 0.5f;
	info->map_info.player_x = j + 0.5f;
	info->map_info.player_dir = dir;
	info->map[i][j] = '0';
	if (dir == S)
	{
		info->map_info.dir_x = 0.0;
		info->map_info.dir_y = 1.0;
		info->map_info.plane_x = 0.66;
		info->map_info.plane_y = 0;
	}
	else if (dir == W)
	{
		info->map_info.dir_x = -1.0;
		info->map_info.dir_y = 0.0;
		info->map_info.plane_x = 0.0;
		info->map_info.plane_y = 0.66;
	}
	else if (dir == E)
	{
		info->map_info.dir_x = 1.0;
		info->map_info.dir_y = 0.0;
		info->map_info.plane_x = 0.0;
		info->map_info.plane_y = -0.66;
	}
}

void	is_valid_info(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (!(info->map[i][j] == '1' || info->map[i][j] == '0'
				|| info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'E' || info->map[i][j] == 'W'
				|| info->map[i][j] == ' '))
				print_error("Error: check again map info\n");
		}
	}
}

void	check_player(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'E' || info->map[i][j] == 'W')
				info->map_info.player_cnt++;
			if (info->map[i][j] == 'N')
				get_player_info(info, i, j, N);
			else if (info->map[i][j] == 'S')
				get_player_info(info, i, j, S);
			else if (info->map[i][j] == 'E')
				get_player_info(info, i, j, E);
			else if (info->map[i][j] == 'W')
				get_player_info(info, i, j, W);
		}
		info->map_width = ft_max(info->map_width, j);
	}
	if (info->map_info.player_cnt != 1)
		print_error("Error: player must be one\n");
}

void	is_valid_map(t_info *info)
{
	is_valid_info(info);
	check_player(info);
	resize_map(info, info->map);
	is_closed(info, info->map);
}

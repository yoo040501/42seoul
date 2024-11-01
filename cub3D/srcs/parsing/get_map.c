/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:16 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/01 15:44:17 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* map 테스트용 함수 */
void	print_map(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (info->map[++i])
	{
		printf("%s\n", info->map[i]);
	}
	printf("%d\n%d\n", info->map_width, info->map_height);
	printf("palyer x: %f\n player y: %f\n", info->map_info.player_x, info->map_info.player_y);
}

/*
	0 이거나 플레이어위치일때 주변(동서남북)에 공백이거나 NULL값이면 둘러쌓여있지 않음
 */
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
					|| map[y][x + 1] == 0)
					print_error("Error: must be surrouned wall\n");
			}
		}
	}
}

void	get_player_info(t_info *info, int i, int j, int dir)
{
	info->map_info.player_y = i;
	info->map_info.player_x = j;
	info->map_info.player_dir = dir;
	info->map[i][j] = '0';
	if (dir == S)
	{
		info->map_info.dir_x = 1.0;
		info->map_info.dir_y = 0.0;
		info->map_info.plane_x = 0;
		info->map_info.plane_y = -0.66;
	}
	else if (dir == W)
	{
		info->map_info.dir_x = 0.0;
		info->map_info.dir_y = -1.0;
		info->map_info.plane_x = -0.66;
		info->map_info.plane_y = 0.0;
	}
	else if (dir == E)
	{
		info->map_info.dir_x = 0.0;
		info->map_info.dir_y = 1.0;
		info->map_info.plane_x = 0.66;
		info->map_info.plane_y = 0.0;
	}
}

/*
	플레이어는 오직 한명만 존재해야한다
*/
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

void	is_vaild_map(t_info *info)
{
	check_player(info);
	is_closed(info, info->map);
	//print_map(info);
}

void	get_map(t_info *info, int fd)
{
	char	*str;
	char	*map_tmp;

	str = get_next_line(fd);
	while (ft_strcmp(str, "\n") == 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	map_tmp = NULL;
	while (str)
	{
		if (ft_strcmp(str, "\n") == 0)
			print_error("Error: must be not empty line\n");
		if (map_tmp == NULL)
			map_tmp = ft_strdup(str);
		else
			map_tmp = ft_strjoin_free(map_tmp, str);
		free(str);
		str = get_next_line(fd);
		(info->map_height)++;
	}
	info->map = ft_split(map_tmp, '\n');
	free(map_tmp);
}

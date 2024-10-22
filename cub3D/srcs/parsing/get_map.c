/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:16 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/21 12:52:55 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_map(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (info->map[++i])
	{
		printf("%s\n", info->map[i]);
	}
	printf("%d\n%d\n", info->width, info->height);
}

/*
	0 이거나 플레이어위치일때 주변(동서남북)에 공백이거나 NULL값이면 둘러쌓여있지 않음
 */
void	is_closed(t_info *info, char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] != '1' && map[x][y] != ' ')
			{
				if (x == 0 || x == info->height - 1
					|| y == 0 || y == info->width - 1
					|| map[x - 1][y] == ' ' || map[x + 1][y] == ' '
					|| map[x][y - 1] == ' ' || map[x][y + 1] == ' '
					|| map[x][y + 1] == 0)
					print_error("Error: must be surrouned wall\n");
			}
		}
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
				info->map_info.player_dir = N;
			else if (info->map[i][j] == 'S')
				info->map_info.player_dir = S;
			else if (info->map[i][j] == 'E')
				info->map_info.player_dir = E;
			else if (info->map[i][j] == 'W')
				info->map_info.player_dir = W;
		}
		info->width = ft_max(info->width, j);
	}
	if (info->map_info.player_cnt != 1)
		print_error("Error: player must be one\n");
}

void	is_vaild_map(t_info *info)
{
	check_player(info);
	is_closed(info, info->map);
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
		(info->height)++;
	}
	info->map = ft_split(map_tmp, '\n');
	free(map_tmp);
}

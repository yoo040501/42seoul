/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:29:00 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/06 11:30:52 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

char	**dup_map(char **map)
{
	int		i;
	char	**dfs_map;

	i = 0;
	while (map[i])
		i++;
	dfs_map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dfs_map)
		print_error("malloc fail");
	dfs_map[i] = NULL;
	i = -1;
	while (map[++i])
		dfs_map[i] = ft_strdup(map[i], 0);
	return (dfs_map);
}

void	dfs(int x, int y, char **map, int *cnt)
{
	if (x <= -1 || y <= -1)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] != 'o')
	{
		if (map[y][x] == 'E' || map[y][x] == 'C')
		{
			map[y][x] = '0';
			*cnt += 1;
			dfs(x, y, map, cnt);
		}
		else
		{
			map[y][x] = 'o';
			dfs(x - 1, y, map, cnt);
			dfs(x + 1, y, map, cnt);
			dfs(x, y - 1, map, cnt);
			dfs(x, y + 1, map, cnt);
		}
	}
}

void	check_valid_map(t_vars *vars)
{
	char	**map_temp;
	int		cnt;

	cnt = 0;
	map_temp = dup_map(vars->map);
	dfs(vars->player_x, vars->player_y, map_temp, &cnt);
	if (cnt != vars->coin_cnt + 1)
		print_error("invalid map");
	free_map(map_temp);
}

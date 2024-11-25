/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:19:29 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/09 14:29:39 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

char	**get_map(char **av)
{
	int		fd;
	int		cnt;
	char	*map_tmp;
	char	*str;
	char	**map;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("file open fail");
	str = get_next_line(fd);
	cnt = 1;
	while (str)
	{
		if (ft_strncmp(str, "\n", 1) == 0)
			print_error("not map");
		if (cnt == 1)
			map_tmp = ft_strdup(str, 1);
		else
			map_tmp = ft_strjoin(map_tmp, str);
		str = get_next_line(fd);
		cnt++;
	}
	close(fd);
	map = ft_split(map_tmp, '\n');
	return (map);
}

void	check_line(char **map)
{
	int	i;
	int	cnt;

	cnt = 1;
	i = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			print_error("must be rectangular");
		else
			cnt++;
	}
	if (cnt < 3)
		print_error("must be at least three lines");
}

void	check_wall(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (i == 0)
			{
				if (map[i][j] != '1')
					print_error("map must be surrounded by wall");
			}
			if (map[i][j + 1] == 0)
				if (map[i][j] != '1')
					print_error("map must be surrounded by wall");
			if (map[i + 1] == 0)
				if (map[i][j] != '1')
					print_error("map must be surrounded by wall");
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				print_error("other flag forbiden");
		}
	}
}

void	check_components(char **map, t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				vars->player++;
			if (map[i][j] == 'C')
				vars->coin_cnt++;
			if (map[i][j] == 'E')
			{
				vars->out++;
				vars->exit_x = j;
				vars->exit_y = i;
			}
		}
	}
	if (vars->player != 1 || vars->out != 1 || vars->coin_cnt < 1)
		print_error("components must contain least one");
	vars->x_max = j;
	vars->y_max = i;
}

void	check_map(t_vars *vars, char **av)
{
	int	i;
	int	j;

	i = -1;
	vars->map = get_map(av);
	check_line(vars->map);
	check_wall(vars->map);
	check_components(vars->map, vars);
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->player_x = j;
				vars->player_y = i;
			}
		}
	}
	check_valid_map(vars);
}

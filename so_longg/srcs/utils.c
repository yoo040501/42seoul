/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:47 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/05 18:09:12 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

void	print_error(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	exit (1);
}

void	put_image(t_vars *vars, void *id, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, id, x, y);
}

void	draw_win(t_vars *vars)
{
	int		i;
	int		j;

	i = -1;
	mlx_clear_window(vars->mlx, vars->win);
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == '1')
				put_image(vars, vars->wall, j * vars->width, i * vars->height);
			else
				put_image(vars, vars->road, j * vars->width, i * vars->height);
			if (vars->map[i][j] == 'P')
				put_image(vars, vars->cat, j * vars->width, i * vars->height);
			if (vars->map[i][j] == 'C')
				put_image(vars, vars->coin, j * vars->width, i * vars->height);
			if (vars->map[i][j] == 'E')
				put_image(vars, vars->door, j * vars->width, i * vars->height);
			if (vars->map[i][j] == 'D')
				put_image(vars, vars->open, j * vars->width, i * vars->height);
		}
	}
}

void	check_coin(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->exit_x;
	y = vars->exit_y;
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->coin_cnt--;
	if (vars->coin_cnt == 0)
	{
		vars->map[vars->exit_y][vars->exit_x] = 'D';
		put_image(vars, vars->road, x * vars->width, y * vars->height);
		put_image(vars, vars->open, x * vars->width, y * vars->height);
	}
}

void	check_exit(t_vars *vars, char flag)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (vars->map[y][x] == 'E')
		put_image(vars, vars->door, vars->width * x, vars->height * y);
	if (flag == 'u' && vars->map[y - 1][x] == 'E')
		put_image(vars, vars->door, vars->width * x, vars->height * (y - 1));
	if (flag == 'd' && vars->map[y + 1][x] == 'E')
		put_image(vars, vars->door, vars->width * x, vars->height * (y + 1));
	if (flag == 'l' && vars->map[y][x - 1] == 'E')
		put_image(vars, vars->door, vars->width * (x - 1), vars->height * y);
	if (flag == 'r' && vars->map[y][x + 1] == 'E')
		put_image(vars, vars->door, vars->width * (x + 1), vars->height * y);
}


int dfs(int x, int y, char **map, char find_char)
{
	int count;

	if (x <= -1 ||y <= -1 )
		return (0);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] != 'o')
	{
		if (map[y][x] == find_char)
		{
			map[y][x] = 'o';
			return (1);
		}
		map[y][x] = 'o';
		count = 0;
		count += dfs(x - 1, y, map, find_char);
		count += dfs(x, y + 1, map, find_char);
		count += dfs(x + 1, y, map, find_char);
		count += dfs(x, y - 1, map, find_char);
		return (count);
	}
	return (0);
}

int	has_valid_path(char **map, t_vars *board)
{
	char	**map_temp_c;
	char	**map_temp_e;

	map_temp_c = duplicate(map);
	map_temp_e = duplicate(map);
 
	int c_count = dfs(player_x, player_y, map_temp_c, 'C');
	int e_count = dfs(player_x, player_y, map_temp_e, 'E');
	if (c_count != board->total_c_count)
		return (0);
	if (e_count != 1)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:22:01 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/05 18:07:41 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

void	move_r(t_vars *vars, int x, int y)
{
	char	**map;

	map = vars->map;
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
	{
		put_image(vars, vars->road, vars->width * x, vars->height * y);
		put_image(vars, vars->road, vars->width * (x + 1), vars->height * y);
		check_exit(vars, 'r');
		put_image(vars, vars->cat, vars->width * (x + 1), vars->height * y);
		if (map[y][x] == 'P')
			map[y][x] = '0';
		vars->player_x++;
		if (map[y][vars->player_x] == 'C')
			check_coin(vars);
		vars->cnt++;
		ft_putstr_fd("cnt:", 1);
		ft_putnbr_fd(vars->cnt, 1);
		ft_putstr_fd("\n", 1);
	}
	if (map[y][x + 1] == 'D')
		closed(vars);
}

void	move_l(t_vars *vars, int x, int y)
{
	char	**map;
	int		w;
	int		h;

	w = vars->width;
	h = vars->height;
	map = vars->map;
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
	{
		put_image(vars, vars->road, vars->width * x, vars->height * y);
		put_image(vars, vars->road, vars->width * (x - 1), vars->height * y);
		check_exit(vars, 'l');
		put_image(vars, vars->cat, vars->width * (x - 1), vars->height * y);
		if (map[y][x] == 'P')
			map[y][x] = '0';
		vars->player_x--;
		if (map[y][vars->player_x] == 'C')
			check_coin(vars);
		vars->cnt++;
		ft_putstr_fd("cnt:", 1);
		ft_putnbr_fd(vars->cnt, 1);
		ft_putstr_fd("\n", 1);
	}
	if (map[y][x - 1] == 'D')
		closed(vars);
}

void	move_u(t_vars *vars, int x, int y)
{
	char	**map;
	int		w;
	int		h;

	w = vars->width;
	h = vars->height;
	map = vars->map;
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
	{
		put_image(vars, vars->road, vars->width * x, vars->height * y);
		put_image(vars, vars->road, vars->width * x, vars->height * (y - 1));
		check_exit(vars, 'u');
		put_image(vars, vars->cat, vars->width * x, vars->height * (y - 1));
		if (map[y][x] == 'P')
			map[y][x] = '0';
		vars->player_y--;
		if (map[vars->player_y][x] == 'C')
			check_coin(vars);
		vars->cnt++;
		ft_putstr_fd("cnt:", 1);
		ft_putnbr_fd(vars->cnt, 1);
		ft_putstr_fd("\n", 1);
	}
	if (map[y - 1][x] == 'D')
		closed(vars);
}

void	move_d(t_vars *vars, int x, int y)
{
	char	**map;
	int		w;
	int		h;

	w = vars->width;
	h = vars->height;
	map = vars->map;
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
	{
		put_image(vars, vars->road, vars->width * x, vars->height * y);
		put_image(vars, vars->road, vars->width * x, vars->height * (y + 1));
		check_exit(vars, 'd');
		put_image(vars, vars->cat, vars->width * x, vars->height * (y + 1));
		if (map[y][x] == 'P')
			map[y][x] = '0';
		vars->player_y++;
		if (map[vars->player_y][x] == 'C')
			check_coin(vars);
		vars->cnt++;
		ft_putstr_fd("cnt:", 1);
		ft_putnbr_fd(vars->cnt, 1);
		ft_putstr_fd("\n", 1);
	}
	if (map[y + 1][x] == 'D')
		closed(vars);
}

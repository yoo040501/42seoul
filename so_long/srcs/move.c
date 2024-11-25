/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:22:01 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/11 13:21:47 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

void	check_coin(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->exit_x;
	y = vars->exit_y;
	if (vars->map[vars->player_y][vars->player_x] == 'C')
		vars->coin_cnt--;
	if (vars->map[vars->player_y][vars->player_x] != 'E')
		vars->map[vars->player_y][vars->player_x] = 'P';
	if (vars->coin_cnt == 0)
		vars->map[vars->exit_y][vars->exit_x] = 'D';
}

void	move_r(t_vars *vars, int x, int y)
{
	char	**map;

	map = vars->map;
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
	{
		if (map[y][x] == 'P')
			map[y][x] = '0';
		vars->player_x++;
		vars->player_f = 'r';
		check_coin(vars);
		draw_win(vars);
		if (map[y][x + 1] == 'E')
			put_img(vars, vars->catr, vars->width * (x + 1), vars->height * y);
		print_cnt(vars);
	}
	if (map[y][x + 1] == 'D')
	{
		print_cnt(vars);
		closed(vars);
	}
}

void	move_l(t_vars *vars, int x, int y)
{
	char	**map;

	map = vars->map;
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
	{
		if (map[y][x] == 'P')
			map[y][x] = '0';
		vars->player_x--;
		vars->player_f = 'l';
		check_coin(vars);
		draw_win(vars);
		if (map[y][x - 1] == 'E')
			put_img(vars, vars->catl, vars->width * (x - 1), vars->height * y);
		print_cnt(vars);
	}
	if (map[y][x - 1] == 'D')
	{
		print_cnt(vars);
		closed(vars);
	}
}

void	move_u(t_vars *vars, int x, int y)
{
	char	**map;

	map = vars->map;
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
	{
		if (map[y][x] == 'P')
			map[y][x] = '0';
		vars->player_y--;
		check_coin(vars);
		draw_win(vars);
		if (map[y - 1][x] == 'E' && vars->player == 'r')
			put_img(vars, vars->catr, vars->width * x, vars->height * (y - 1));
		if (map[y - 1][x] == 'E' && vars->player == 'l')
			put_img(vars, vars->catl, vars->width * x, vars->height * (y - 1));
		print_cnt(vars);
	}
	if (map[y - 1][x] == 'D')
	{	
		print_cnt(vars);
		closed(vars);
	}
}

void	move_d(t_vars *vars, int x, int y)
{
	char	**map;

	map = vars->map;
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
	{
		if (map[y][x] == 'P')
			map[y][x] = '0';
		vars->player_y++;
		check_coin(vars);
		draw_win(vars);
		if (map[y + 1][x] == 'E' && vars->player_f == 'r')
			put_img(vars, vars->catr, vars->width * x, vars->height * (y + 1));
		if (map[y + 1][x] == 'E' && vars->player_f == 'l')
			put_img(vars, vars->catl, vars->width * x, vars->height * (y + 1));
		print_cnt(vars);
	}
	if (map[y + 1][x] == 'D')
	{
		print_cnt(vars);
		closed(vars);
	}
}

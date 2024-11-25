/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:47 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/11 13:22:16 by dongeunk         ###   ########.fr       */
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

void	print_cnt(t_vars *vars)
{
	vars->cnt++;
	ft_putstr_fd("count: ", 1);
	ft_putnbr_fd(vars->cnt, 1);
	ft_putchar_fd('\n', 1);
}

void	put_img(t_vars *vars, void *id, int x, int y)
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
			{
				put_img(vars, vars->wall, j * vars->width, i * vars->height);
				put_img(vars, vars->tree, j * vars->width, i * vars->height);
			}
			else
				put_img(vars, vars->road, j * vars->width, i * vars->height);
			draw_char(vars, i, j);
		}
	}
}

void	draw_char(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'P' && vars->player_f == 'r')
		put_img(vars, vars->catr, j * vars->width, i * vars->height);
	if (vars->map[i][j] == 'P' && vars->player_f == 'l')
		put_img(vars, vars->catl, j * vars->width, i * vars->height);
	if (vars->map[i][j] == 'C')
		put_img(vars, vars->coin, j * vars->width, i * vars->height);
	if (vars->map[i][j] == 'E')
		put_img(vars, vars->door, j * vars->width, i * vars->height);
	if (vars->map[i][j] == 'D')
		put_img(vars, vars->open, j * vars->width, i * vars->height);
}

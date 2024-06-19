/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:18:17 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/05 16:24:20 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

int	key_hook(int key, t_vars *vars)
{
	int	i;

	i = 0;
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (key == KEY_W || key == KEY_UP)
		move_u(vars, vars->player_x, vars->player_y);
	else if (key == KEY_A || key == KEY_LEFT)
		move_l(vars, vars->player_x, vars->player_y);
	else if (key == KEY_S || key == KEY_DOWN)
		move_d(vars, vars->player_x, vars->player_y);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_r(vars, vars->player_x, vars->player_y);
	return (0);
}

int	closed(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	vars_init(t_vars *vars)
{
	int	w;
	int	h;

	vars->mlx = mlx_init();
	vars->cat = mlx_xpm_file_to_image(vars->mlx, "./images/cat.xpm", &w, &h);
	vars->road = mlx_xpm_file_to_image(vars->mlx, "./images/road.xpm", &w, &h);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./images/Water.xpm", &w, &h);
	vars->coin = mlx_xpm_file_to_image(vars->mlx, "./images/Wall1.xpm", &w, &h);
	vars->door = mlx_xpm_file_to_image(vars->mlx, "./images/Wall5.xpm", &w, &h);
	vars->open = mlx_xpm_file_to_image(vars->mlx, "./images/Road0.xpm", &w, &h);
	vars->x_max = 0;
	vars->y_max = 0;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->player = 0;
	vars->out = 0;
	vars->coin_cnt = 0;
	vars->cnt = 0;
	vars->width = w;
	vars->height = h;
}

int	main(void)
{
	t_vars	vars;
	int		i;

	i = -1;
	vars_init(&vars);
	check_map(&vars);
	vars.x_max *= vars.width;
	vars.y_max *= vars.height;
	vars.win = mlx_new_window(vars.mlx, vars.x_max, vars.y_max, "so_long");
	draw_win(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, ESCPRESS, 0, closed, &vars);
	mlx_loop(vars.mlx);
	exit (0);
}

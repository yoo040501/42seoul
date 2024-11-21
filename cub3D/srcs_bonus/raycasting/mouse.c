/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:01:30 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 14:23:28 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	check_x(int *x, t_window *window)
{
	if (*x < WIDTH * 4 / 10)
	{
		window->key_flag.mouse_l = 1;
		window->key_flag.mouse_r = 0;
		*x = WIDTH * 4 / 10;
	}
	else if (*x > WIDTH * 6 / 10)
	{
		window->key_flag.mouse_l = 0;
		window->key_flag.mouse_r = 1;
		*x = WIDTH * 6 / 10 + 1;
	}
	else
	{
		window->key_flag.mouse_l = 0;
		window->key_flag.mouse_r = 0;
	}
}

static void	check_y(int *y, t_window *window)
{
	if (*y < HEIGHT * 4 / 10)
	{
		window->key_flag.mouse_u = 1;
		window->key_flag.mouse_d = 0;
		*y = HEIGHT * 4 / 10 - 1;
	}
	else if (*y > HEIGHT * 6 / 10)
	{
		window->key_flag.mouse_u = 0;
		window->key_flag.mouse_d = 1;
		*y = HEIGHT * 6 / 10 + 1;
	}
	else
	{
		window->key_flag.mouse_u = 0;
		window->key_flag.mouse_d = 0;
	}
}

int	check_mouse(int x, int y, t_window *window)
{
	check_x(&x, window);
	check_y(&y, window);
	mlx_mouse_move(window->win, x, y);
	return (0);
}

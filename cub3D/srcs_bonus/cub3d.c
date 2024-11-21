/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:42:55 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 14:03:17 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	closed(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
}

int	main_loop(t_window *window)
{
	calc(window);
	draw(window);
	key_move(window);
	if (window->key_flag.key_mode == 1)
		window->camera_height = 0.5;
	else if (window->key_flag.key_mode == 2)
		mouse_move(window);
	return (0);
}

void	execute(char **argv)
{
	char		*path;
	t_info		*info;
	t_window	*window;

	path = check_file(argv[1]);
	info = info_init();
	check_in_file(path, info);
	printf("check finish\n");
	window = window_init(info);
	printf("Game start!!\n");
	mlx_mouse_hide();
	mlx_loop_hook(window->mlx, &main_loop, window);
	mlx_hook(window->win, KEYPRESS, 0, &key_press, window);
	mlx_hook(window->win, KEYRELEASE, 0, &key_release, window);
	mlx_hook(window->win, ESCPRESS, 0, &closed, window);
	mlx_hook(window->win, MOUSEMOVE, 0, &check_mouse, window);
	mlx_loop(window->mlx);
	ft_free((void **)&path);
	free_window(window);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		print_error("Error: argument must need two\n");
	else
		execute(argv);
	return (0);
}

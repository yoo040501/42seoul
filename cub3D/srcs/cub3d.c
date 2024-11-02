/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:42:55 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/02 15:34:31 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_leak(void)
{
	system("leaks cub3D");
}

void	print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	exit(1);
}

int	main_loop(t_window *window)
{
	calc(window);
	draw(window);
	key_move(window);
	return (0);
}

int	closed(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	char		*path;
	t_info		*info;
	t_window	*window;

	//atexit(check_leak);
	if (argc != 2)
		print_error("Error: need map file\n");
	path = check_file(argv[1]);
	info = info_init();
	check_in_file(path, info);
	printf("check finish\n");
	window = window_init(info);
	printf("init finish\n");
	mlx_loop_hook(window->mlx, &main_loop, window);
	mlx_hook(window->win, KEYPRESS, 0, &key_press, window);
	mlx_hook(window->win, KEYRELEASE, 0, &key_release, window);
	mlx_hook(window->win, ESCPRESS, 0, &closed, window);
	mlx_loop(window->mlx);
	ft_free((void **)&path);
	free_window(window);
	return (0);
}

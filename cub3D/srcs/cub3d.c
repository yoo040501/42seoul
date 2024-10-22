/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:42:55 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/16 18:42:56 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_leak(void)
{
	system("leaks cub3d");
}

void	print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	char	*path;
	t_info	*info;

	//atexit(check_leak);
	if (argc != 2)
		print_error("Error: need map file\n");
	path = check_file(argv[1]);
	info = info_init();
	check_in_file(path, info);
	ft_free((void **)&path);
	free_info(info);
	return (0);
}

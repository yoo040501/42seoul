/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:10 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/14 19:26:26 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	check_file_open(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		print_error("Error: map can't open\n");
		exit (1);
	}
	close(fd);
}

char	*get_path(char *av)
{
	char	*map;

	if (ft_strncmp(av, "map/", 4))
		map = ft_strjoin("map/", av);
	else
		map = ft_strdup(av);
	return (map);
}

void	check_file_name(const char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len <= 4)
		print_error("Error: map name unavailable\n");
	if (ft_strcmp(map + (len - 4), ".cub"))
		print_error("Error: map must be finish .cub\n");
}

char	*check_file(char *av)
{
	char	*path;

	printf("Make&Check map path...~ing\n");
	check_file_name(av);
	path = get_path(av);
	check_file_open(path);
	return (path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:10 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/16 18:43:11 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	check_file_name(av); // map이름 검사
	path = get_path(av); // map복사
	check_file_open(path); // map 파일 있는지
	return (path);
}
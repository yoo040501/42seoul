/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:16 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/15 21:14:18 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	resize_map(t_info *info, char **map)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	tmp = (char **)ft_calloc(sizeof(char *), (info->map_height + 1));
	tmp[info->map_height] = NULL;
	while (++i < info->map_height)
		tmp[i] = (char *)ft_calloc(sizeof(char), (info->map_width + 1));
	i = -1;
	while (++i < info->map_height)
	{
		j = -1;
		while (map[i][++j])
			tmp[i][j] = map[i][j];
		j--;
		while (++j < info->map_width)
			tmp[i][j] = ' ';
		tmp[i][info->map_width] = 0;
	}
	ft_free_2d((void **)info->map);
	info->map = tmp;
}

void	get_map(t_info *info, int fd)
{
	char	*str;
	char	*map_tmp;

	str = get_next_line(fd);
	while (ft_strcmp(str, "\n") == 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	map_tmp = NULL;
	while (str)
	{
		if (ft_strcmp(str, "\n") == 0)
			print_error("Error: must be not empty line\n");
		if (map_tmp == NULL)
			map_tmp = ft_strdup(str);
		else
			map_tmp = ft_strjoin_free(map_tmp, str);
		free(str);
		str = get_next_line(fd);
		(info->map_height)++;
	}
	info->map = ft_split(map_tmp, '\n');
	free(map_tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:14 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 11:10:11 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_texture_path(char *texture, t_info *info, char *path, int dir)
{
	int		fd;
	char	*path_nl;

	if (path)
		return (FALSE);
	path_nl = cut_nl(texture);
	path = ft_strtrim(path_nl, " ");
	ft_free((void **)&path_nl);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	info->text->texture_cnt++;
	if (dir == N)
		info->text->n_path = path;
	else if (dir == S)
		info->text->s_path = path;
	else if (dir == W)
		info->text->w_path = path;
	else
		info->text->e_path = path;
	return (TRUE);
}

char	*cut_nl(char *path)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(path);
	str = (char *)ft_calloc(sizeof(char), len);
	i = 0;
	while (path[i] != '\n')
	{
		str[i] = path[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

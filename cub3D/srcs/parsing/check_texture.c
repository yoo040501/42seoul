/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:14 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/01 13:13:04 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_no_path(char *texture, t_info *info, int *flag)
{
	int		fd;
	char	*path_tmp;
	char	*path;

	if (info->text->n_path) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	path_tmp = cut_nl(texture);
	path = ft_strtrim(path_tmp, " ");
	ft_free((void **)&path_tmp);
	fd = open(path, O_RDONLY);
	if (fd < 0) // 경로가 잘못됬으면 에러
	{
		*flag = FALSE;
		return ;
	}
	close(fd);
	info->text->n_path = path;
	info->text->texture_cnt++;
}

void	get_so_path(char *texture, t_info *info, int *flag)
{
	int		fd;
	char	*path_tmp;
	char	*path;

	if (info->text->s_path) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	path_tmp = cut_nl(texture);
	path = ft_strtrim(path_tmp, " ");
	ft_free((void **)&path_tmp);
	fd = open(path, O_RDONLY);
	if (fd < 0) // 경로가 잘못됬으면 에러
	{
		*flag = FALSE;
		return ;
	}
	close(fd);
	info->text->s_path = path;
	info->text->texture_cnt++;
}

void	get_we_path(char *texture, t_info *info, int *flag)
{
	int		fd;
	char	*path_tmp;
	char	*path;

	if (info->text->w_path) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	path_tmp = cut_nl(texture);
	path = ft_strtrim(path_tmp, " ");
	ft_free((void **)&path_tmp);
	fd = open(path, O_RDONLY);
	if (fd < 0) // 경로가 잘못됬으면 에러
	{
		*flag = FALSE;
		return ;
	}
	close(fd);
	info->text->w_path = path;
	info->text->texture_cnt++;
}

void	get_ea_path(char *texture, t_info *info, int *flag)
{
	int		fd;
	char	*path_tmp;
	char	*path;

	if (info->text->e_path) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	path_tmp = cut_nl(texture);
	path = ft_strtrim(path_tmp, " ");
	ft_free((void **)&path_tmp);
	fd = open(path, O_RDONLY);
	if (fd < 0) // 경로가 잘못됬으면 에러
	{
		*flag = FALSE;
		return ;
	}
	close(fd);
	info->text->e_path = path;
	info->text->texture_cnt++;
}

char	*cut_nl(char *path)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(path);
	str = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (path[i] != '\n')
	{
		str[i] = path[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

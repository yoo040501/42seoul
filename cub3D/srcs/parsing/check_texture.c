/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:14 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/16 18:46:01 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_no_path(char *texture, t_info *info, int *flag)
{
	int		fd;
	char	*path;

	if (info->text->n_path) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	path = cut_nl(texture);
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
	char	*path;

	if (info->text->s_path) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	path = cut_nl(texture);
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
	char	*path;

	if (info->text->w_path) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	path = cut_nl(texture);
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
	char	*path;

	if (info->text->e_path) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	path = cut_nl(texture);
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

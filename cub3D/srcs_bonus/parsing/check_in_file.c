/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:11 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 13:55:09 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	is_texture(char *str, t_info *info)
{
	int		flag;

	flag = TRUE;
	if (ft_strncmp(str, "NO ", 3) == 0)
		flag = get_texture_path(str + 2, info, info->text->n_path, N);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		flag = get_texture_path(str + 2, info, info->text->s_path, S);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		flag = get_texture_path(str + 2, info, info->text->w_path, W);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		flag = get_texture_path(str + 2, info, info->text->e_path, E);
	else if (ft_strncmp(str, "F ", 2) == 0)
		flag = get_color(str + 2, info, info->text->f_color, 0);
	else if (ft_strncmp(str, "C ", 2) == 0)
		flag = get_color(str + 2, info, info->text->c_color, 1);
	else
		flag = FALSE;
	return (flag);
}

int	is_map(char str)
{
	if (str == ' ' || str == '0' || str == '1')
		return (TRUE);
	return (FALSE);
}

void	check_texture(t_info *info, int fd)
{
	char	*str;

	while (info->text->texture_cnt < 6)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		else if (ft_strcmp(str, "\n") == 0)
			;
		else if (is_map(str[0]))
			break ;
		else if (is_texture(str, info) == FALSE)
			break ;
		ft_free((void **)&str);
	}
	if (str)
		ft_free((void **)&str);
	if (info->text->f_color == -1 || info->text->c_color == -1
		|| info->text->texture_cnt != 6)
		close(fd);
	if (info->text->texture_cnt != 6)
		print_error("Error: check again texture\n");
	if (info->text->f_color == -1 || info->text->c_color == -1)
		print_error("Error: color value should be between 0 and 255\n");
}

void	check_in_file(char *path, t_info *info)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Error: open fail\n");
	check_texture(info, fd);
	if (is_dup_texture(info) == FALSE)
	{
		close(fd);
		print_error("Error: texture is duplicated\n");
	}
	get_map(info, fd);
	close(fd);
	is_valid_map(info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:14 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 14:05:53 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	get_int(char **color)
{
	int	value;
	int	tmp;
	int	i;

	i = -1;
	value = 0;
	while (color[++i])
	{
		tmp = ft_atoi(color[i]);
		if (tmp < 0 || tmp > 255)
			return (-1);
		value = value << 8;
		value += tmp;
	}
	return (value);
}

static int	check_color_valid(char **color_tmp, int color)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (color_tmp[++i])
	{
		if (color_tmp[i][0])
			cnt++;
	}
	if (cnt != 3 || color >= 0)
	{
		ft_free_2d((void **)color_tmp);
		return (0);
	}
	else
		return (1);
}

int	get_color(char *texture, t_info *info, int color, int dir)
{
	char	*tmp;
	char	**color_tmp;
	int		i;

	tmp = cut_nl(texture);
	color_tmp = ft_split(tmp, ',');
	ft_free((void **)&tmp);
	if (!color_tmp)
		print_error("Error: malloc fail\n");
	i = -1;
	while (color_tmp[++i])
		color_tmp[i] = ft_strtrim_free(color_tmp[i], " ");
	if (check_color_valid(color_tmp, color) == FALSE)
		return (FALSE);
	color = get_int(color_tmp);
	ft_free_2d((void **)color_tmp);
	if (color < 0)
		return (FALSE);
	if (dir == 0)
		info->text->f_color = color;
	else
		info->text->c_color = color;
	info->text->texture_cnt++;
	return (TRUE);
}

int	is_dup_texture(t_info *info)
{
	int	flag;

	flag = TRUE;
	if (ft_strcmp(info->text->n_path, info->text->s_path) == 0)
		flag = FALSE;
	else if (ft_strcmp(info->text->n_path, info->text->e_path) == 0)
		flag = FALSE;
	else if (ft_strcmp(info->text->n_path, info->text->w_path) == 0)
		flag = FALSE;
	else if (ft_strcmp(info->text->s_path, info->text->e_path) == 0)
		flag = FALSE;
	else if (ft_strcmp(info->text->s_path, info->text->w_path) == 0)
		flag = FALSE;
	else if (ft_strcmp(info->text->e_path, info->text->w_path) == 0)
		flag = FALSE;
	if (info->text->c_color == info->text->f_color)
		flag = FALSE;
	return (flag);
}

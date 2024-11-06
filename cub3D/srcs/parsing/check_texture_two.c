/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:14 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/04 13:25:39 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color(char **color)
{
	int	value;
	int	tmp;
	int	i;

	i = -1;
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

void	get_c_color(char *texture, t_info *info, int *flag)
{
	char	*tmp;
	char	**color;
	int		i;

	tmp = cut_nl(texture);
	color = ft_split(tmp, ',');
	ft_free((void **)&tmp);
	if (!color)
		print_error("Error: malloc fail\n");
	i = -1;
	while (color[++i])
		color[i] = ft_strtrim_free(color[i], " ");
	if (info->text->c_color >= 0 || color[3] != NULL)
	{
		ft_free_2d((void **)color);
		*flag = FALSE;
		return ;
	}
	info->text->c_color = get_color(color);
	ft_free_2d((void **)color);
	if (info->text->c_color < 0)
		*flag = FALSE;
	info->text->texture_cnt++;
}

void	get_f_color(char *texture, t_info *info, int *flag)
{
	char	*tmp;
	char	**color;
	int		i;

	tmp = cut_nl(texture);
	color = ft_split(tmp, ',');
	ft_free((void **)&tmp);
	if (!color)
		print_error("Error: malloc fail\n");
	i = -1;
	while (color[++i])
		color[i] = ft_strtrim_free(color[i], " ");
	if (info->text->f_color >= 0 || color[3] != NULL)
	{
		ft_free_2d((void **)color);
		*flag = FALSE;
		return ;
	}
	info->text->f_color = get_color(color);
	ft_free_2d((void **)color);
	if (info->text->f_color < 0)
		*flag = FALSE;
	info->text->texture_cnt++;
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

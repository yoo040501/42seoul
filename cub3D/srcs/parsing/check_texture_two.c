/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:14 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/16 18:45:53 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_c_color(char *color, t_info *info, int *flag)
{
	if (info->text->c_color) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	info->text->c_color = ft_strdup(color);
	info->text->texture_cnt++;
}

void	get_f_color(char *color, t_info *info, int *flag)
{
	if (info->text->f_color) // 이미 저장되어있으면 에러
	{
		*flag = FALSE;
		return ;
	}
	info->text->f_color = ft_strdup(color);
	info->text->texture_cnt++;
}

int	is_dup_texture(t_info *info)
{
	int	flag;

	flag = TRUE;
	if (ft_strcmp(info->text->c_color, info->text->f_color) == 0)
		flag = FALSE;
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
	return (flag);
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

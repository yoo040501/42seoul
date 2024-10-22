/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:15 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/16 18:44:57 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free(void **target)
{
	if (target != NULL && (*target) != NULL)
	{
		free(*target);
		*target = NULL;
	}
}

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_free((void **)&str[i]);
		i++;
	}
	ft_free((void **)&str);
}

void	free_info(t_info *info)
{
	int	i;

	i = -1;
	if (info->map)
	{
		ft_free_2d(info->map);
	}
	if (info->text->c_color)
		ft_free((void **)&(info->text->c_color));
	if (info->text->f_color)
		ft_free((void **)&(info->text->f_color));
	if (info->text->n_path)
		ft_free((void **)&(info->text->n_path));
	if (info->text->e_path)
		ft_free((void **)&(info->text->e_path));
	if (info->text->s_path)
		ft_free((void **)&(info->text->s_path));
	if (info->text->w_path)
		ft_free((void **)&(info->text->w_path));
	ft_free((void **)&(info->text));
	ft_free((void **)&(info));
}

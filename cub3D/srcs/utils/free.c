/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:15 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/01 16:02:01 by dongeunk         ###   ########.fr       */
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

void	ft_free_2d(void **str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_free((void **)&str[i]);
	ft_free((void **)&str);
}

void	free_info(t_info *info)
{
	int	i;

	i = -1;
	if (info->map)
		ft_free_2d((void **)info->map);
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

void	free_window(t_window *w)
{
	int	i;

	i = -1;
	if (w->texture)
		ft_free_2d((void **)w->texture);
	if (w->buf)
		ft_free_2d((void **)w->buf);
	if (w->info)
		free_info(w->info);
	if (w->mlx)
		ft_free((void **)&w->mlx);
	if (w->win)
		ft_free((void **)&w->win);
}

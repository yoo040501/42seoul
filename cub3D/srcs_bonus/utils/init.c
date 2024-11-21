/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:17 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/15 21:15:07 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	get_max_image(t_window *window, t_text *text, t_img *i)
{
	int	width;
	int	height;

	is_image(window, text->n_path, i);
	mlx_destroy_image(window->mlx, i->img);
	height = i->img_height;
	width = i->img_width;
	is_image(window, text->s_path, i);
	mlx_destroy_image(window->mlx, i->img);
	i->img_height = ft_max(i->img_height, height);
	i->img_width = ft_max(i->img_width, width);
	is_image(window, text->w_path, i);
	mlx_destroy_image(window->mlx, i->img);
	i->img_height = ft_max(i->img_height, height);
	i->img_width = ft_max(i->img_width, width);
	is_image(window, text->e_path, i);
	mlx_destroy_image(window->mlx, i->img);
	i->img_height = ft_max(i->img_height, height);
	i->img_width = ft_max(i->img_width, width);
}

t_text	*text_init(void)
{
	t_text	*text;

	text = (t_text *)ft_calloc(sizeof(t_text), 1);
	text->texture_cnt = 0;
	text->n_path = NULL;
	text->w_path = NULL;
	text->e_path = NULL;
	text->s_path = NULL;
	text->c_color = -1;
	text->f_color = -1;
	return (text);
}

static void	map_init(t_map *map_info)
{
	map_info->player_x = 0;
	map_info->player_y = 0;
	map_info->player_cnt = 0;
	map_info->player_dir = 0;
	map_info->plane_x = -0.66;
	map_info->plane_y = 0.0;
	map_info->dir_x = 0.0;
	map_info->dir_y = -1.0;
}

t_info	*info_init(void)
{
	t_info	*info;

	info = (t_info *)ft_calloc(sizeof(t_info), 1);
	info->map = NULL;
	info->map_height = 0;
	info->map_width = 0;
	info->text = text_init();
	map_init(&info->map_info);
	return (info);
}

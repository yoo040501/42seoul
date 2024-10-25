/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:17 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/25 14:14:03 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_text	*text_init(void)
{
	t_text	*text;

	text = (t_text *)malloc(sizeof(t_text));
	if (!text)
		print_error("Error: text malloc fail\n");
	text->texture_cnt = 0;
	text->n_path = NULL;
	text->w_path = NULL;
	text->e_path = NULL;
	text->s_path = NULL;
	text->c_color = NULL;
	text->f_color = NULL;
	return (text);
}

void	map_init(t_map *map_info)
{
	map_info->plane_x = 0;
	map_info->plane_y = 0;
	map_info->player_x = 0;
	map_info->player_y = 0;
	map_info->player_cnt = 0;
	map_info->player_dir = 0;
}

t_info	*info_init(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		print_error("Error: info malloc fail\n");
	info->map = NULL;
	info->height = 0;
	info->width = 0;
	info->text = text_init();
	map_init(&info->map_info);
	return (info);
}

t_window	*window_init(t_info *info)
{
	t_window	*vars;
	int		w;
	int		h;
	
	vars = (t_window *)malloc(sizeof(t_window));
	if(!vars)
		print_error("Error: vars malloc fail\n");
	vars->mlx = mlx_init();
	vars->n_wall = mlx_xpm_file_to_image(vars->mlx, info->text->n_path, &w, &h);
	vars->w_wall = mlx_xpm_file_to_image(vars->mlx, info->text->w_path, &w, &h);
	vars->e_wall = mlx_xpm_file_to_image(vars->mlx, info->text->e_path, &w, &h);
	vars->s_wall = mlx_xpm_file_to_image(vars->mlx, info->text->s_path, &w, &h);
	vars->width = w;
	vars->height = h;
	vars->info = info;
}

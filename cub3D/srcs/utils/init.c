/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:17 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/01 15:58:13 by dongeunk         ###   ########.fr       */
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
	text->c_color = -1;
	text->f_color = -1;
	return (text);
}

void	map_init(t_map *map_info)
{
	map_info->player_x = 0;
	map_info->player_y = 0;
	map_info->player_cnt = 0;
	map_info->player_dir = 0;
	map_info->plane_x = 0;
	map_info->plane_y = 0.66;
	map_info->dir_x = -1.0;
	map_info->dir_y = 0.0;
}

t_info	*info_init(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		print_error("Error: info malloc fail\n");
	info->map = NULL;
	info->map_height = 0;
	info->map_width = 0;
	info->text = text_init();
	map_init(&info->map_info);
	return (info);
}

void	set_value(t_window *w)
{
	t_img	*i;

	w->key_a = 0;
	w->key_d = 0;
	w->key_s = 0;
	w->key_w = 0;
	w->key_l = 0;
	w->key_r = 0;
	w->move_speed = 0.05;
	w->rot_speed = 0.05;
	load_texture(w);
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "cub3D");
	i = &(w->img);
	i->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	i->data = (int *)mlx_get_data_addr(i->img, &i->bpp, &i->size_l, &i->endian);
}

t_window	*window_init(t_info *info)
{
	int			i;
	t_window	*w;

	w = (t_window *)malloc(sizeof(t_window));
	w->mlx = mlx_init();
	w->info = info;
	w->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	i = -1;
	while (++i < HEIGHT)
		w->buf[i] = ft_calloc(WIDTH, sizeof(int));
	w->texture = (int **)malloc(sizeof(int *) * 4);
	if (!(w->texture))
		print_error("Error: texture malloc fail\n");
	i = -1;
	while (++i < 4)
	{
		w->texture[i] = ft_calloc(TEXHEIGHT * TEXWIDTH, sizeof(int));
		if (!(w->texture[i]))
			print_error("Error: texture malloc fail\n");
	}
	set_value(w);
	return (w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:54:15 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 12:53:02 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	is_image(t_window *window, char *path, t_img *i)
{
	i->img = mlx_xpm_file_to_image(window->mlx, path,
			&i->img_width, &i->img_height);
	if (!i->img)
		print_error("Error: not image\n");
}

static void	load_image(t_window *window, int *texture, char *path, t_img *i)
{
	int	y;
	int	x;

	is_image(window, path, i);
	i->data = (int *)mlx_get_data_addr(i->img, &i->bpp, &i->size_l, &i->endian);
	y = -1;
	while (++y < i->img_height)
	{
		x = -1;
		while (++x < i->img_width)
			texture[i->img_width * y + x]
				= i->data[i->img_width * y + i->img_width - x - 1];
	}
	mlx_destroy_image(window->mlx, i->img);
}

static void	load_texture(t_window *window)
{
	int		i;
	t_img	img;
	t_text	*text;

	text = window->info->text;
	get_max_image(window, text, &img);
	i = -1;
	while (++i < 4)
	{
		window->texture[i] = ft_calloc(img.img_height
				* img.img_width, sizeof(int));
	}
	load_image(window, window->texture[0], text->n_path, &img);
	load_image(window, window->texture[1], text->s_path, &img);
	load_image(window, window->texture[2], text->e_path, &img);
	load_image(window, window->texture[3], text->w_path, &img);
	get_max_image(window, text, &img);
	window->img = img;
}

void	set_value(t_window *w)
{
	t_img	*i;

	ft_memset(&w->key_flag, 0, sizeof(t_key));
	w->move_speed = 0.05;
	w->rot_speed = 0.05;
	w->camera_height = 0.5;
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

	w = (t_window *)ft_calloc(sizeof(t_window), 1);
	w->mlx = mlx_init();
	w->info = info;
	w->buf = (int **)ft_calloc(sizeof(int *), HEIGHT);
	i = -1;
	while (++i < HEIGHT)
		w->buf[i] = ft_calloc(WIDTH, sizeof(int));
	w->texture = (int **)ft_calloc(sizeof(int *), 4);
	ft_memset(&w->mouse, 0, sizeof(t_mouse));
	set_value(w);
	return (w);
}

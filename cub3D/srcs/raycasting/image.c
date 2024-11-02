/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:02:36 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/02 15:29:46 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw(t_window *window)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			window->img.data[y * WIDTH + x] = window->buf[y][x];
	}
	mlx_put_image_to_window(window->mlx, window->win, window->img.img, 0, 0);
}

void	load_image(t_window *window, int *texture, char *path, t_img *i)
{
	int	y;
	int	x;

	i->img = mlx_xpm_file_to_image(window->mlx, path,
			&i->img_width, &i->img_height);
	i->data = (int *)mlx_get_data_addr(i->img, &i->bpp, &i->size_l, &i->endian);
	y = -1;
	while (++y < i->img_height)
	{
		x = -1;
		while (++x < i->img_width)
			texture[i->img_width * y + x] = i->data[i->img_width * y + x];
	}
	mlx_destroy_image(window->mlx, i->img);
}

void	load_texture(t_window *window)
{
	t_img	img;
	t_text	*text;

	text = window->info->text;
	load_image(window, window->texture[0], text->n_path, &img);
	load_image(window, window->texture[1], text->s_path, &img);
	load_image(window, window->texture[2], text->e_path, &img);
	load_image(window, window->texture[3], text->w_path, &img);
}

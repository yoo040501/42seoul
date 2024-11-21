/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:02:36 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 11:29:07 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

static void	set_wall_image(t_raycast *r, t_draw *d)
{
	if (r->side == 0)
	{
		if (r->raydir_x < 0)
			d->tex_num = E;
		else
			d->tex_num = W;
	}
	else
	{
		if (r->raydir_y > 0)
			d->tex_num = S;
		else
			d->tex_num = N;
	}
}

static void	draw_wall(t_window *window, t_draw d, int x, double height_offset)
{
	int	y;

	d.step = 1.0 * window->img.img_height / d.line_height;
	d.tex_pos = (d.draw_start - HEIGHT / 2 + d.line_height / 2
			- height_offset) * d.step;
	y = d.draw_start;
	while (++y < d.draw_end)
	{
		d.tex_y = (int)d.tex_pos & (window->img.img_height - 1);
		d.tex_pos += d.step;
		window->buf[y][WIDTH - x - 1] = window->texture[d.tex_num]
		[window->img.img_height * d.tex_y + d.tex_x];
	}
}

void	save_wall(t_window *window, t_map *info, t_raycast *r, int x)
{
	t_draw	d;
	double	height_offset;

	height_offset = HEIGHT * (window->camera_height - 0.5);
	d.line_height = (int)(HEIGHT / r->perpwalldist);
	d.draw_start = -d.line_height / 2 + HEIGHT / 2 + height_offset;
	d.draw_end = d.line_height / 2 + HEIGHT / 2 + height_offset;
	if (d.draw_start < 0)
		d.draw_start = 0;
	if (d.draw_end >= HEIGHT)
		d.draw_end = HEIGHT - 1;
	set_wall_image(r, &d);
	if (r->side == 0)
		d.wall_x = info->player_y + r->perpwalldist * r->raydir_y;
	else
		d.wall_x = info->player_x + r->perpwalldist * r->raydir_x;
	d.wall_x -= floor(d.wall_x);
	d.tex_x = (int)(d.wall_x * (double)window->img.img_width);
	if (r->side == 0 && r->raydir_x > 0)
		d.tex_x = window->img.img_width - d.tex_x - 1;
	if (r->side == 1 && r->raydir_y < 0)
		d.tex_x = window->img.img_width - d.tex_x - 1;
	draw_wall(window, d, x, height_offset);
}

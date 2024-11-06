/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:19 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/06 15:34:18 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_wall_image(t_raycast *r, t_draw *d)
{
	if (r->side == 0)
	{
		if (r->raydir_x < 0)
			d->tex_num = 3;
		else
			d->tex_num = 2;
	}
	else
	{
		if (r->raydir_y > 0)
			d->tex_num = 1;
		else
			d->tex_num = 0;
	}
}

void	save_wall(t_window *window, t_map *info, t_raycast *r, int x)
{
	int		y;
	t_draw	d;

	d.line_hegiht = (int)(HEIGHT / r->perpwalldist);
	d.draw_start = -d.line_hegiht * (1.0 - window->camera_height) + HEIGHT / 2;
	if (d.draw_start < 0)
		d.draw_start = 0;
	d.draw_end = d.line_hegiht * (window->camera_height) + HEIGHT / 2;
	if (d.draw_end >= HEIGHT)
		d.draw_end = HEIGHT - 1;
	set_wall_image(r, &d);
	if (r->side == 0)
		d.wall_x = info->player_y + r->perpwalldist * r->raydir_y;
	else
		d.wall_x = info->player_x + r->perpwalldist * r->raydir_x;
	d.wall_x -= floor(d.wall_x);
	d.tex_x = (int)(d.wall_x * (double)TEXWIDTH);
	if (r->side == 0 && r->raydir_x > 0)
		d.tex_x = TEXWIDTH - d.tex_x - 1;
	if (r->side == 1 && r->raydir_y < 0)
		d.tex_x = TEXWIDTH - d.tex_x - 1;
	d.step = 1.0 * TEXWIDTH / d.line_hegiht;
	d.tex_pos = (d.draw_start - HEIGHT / 2 + d.line_hegiht * (1.0 - window->camera_height)) * d.step;
	y = d.draw_start;
	while (++y < d.draw_end)
	{
		d.tex_y = (int)d.tex_pos & (TEXHEIGHT - 1);
		d.tex_pos += d.step;
		window->buf[y][WIDTH - x - 1] = window->texture[d.tex_num]
		[TEXHEIGHT * d.tex_y + d.tex_x];
	}
}

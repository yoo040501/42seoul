/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:19 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/02 15:32:53 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	save_floor(t_window *window, t_floor *f, int y)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		f->cell_x = (int)(f->floor_x);
		f->cell_y = (int)(f->floor_y);
		// get the texture coordinate from the fractional part
		f->tx = (int)(TEXWIDTH * (f->floor_x - f->cell_x)) & (TEXWIDTH - 1);
		f->ty = (int)(TEXHEIGHT * (f->floor_y - f->cell_y)) & (TEXHEIGHT - 1);
		f->floor_x += f->floorstep_x;
		f->floor_y += f->floorstep_y;
		// floor
		window->buf[y][x] = window->info->text->f_color;
		// celling
		window->buf[HEIGHT - y - 1][x] = window->info->text->c_color;
	}
}

void	save_wall(t_window *window, t_map *info, t_raycast *r, int x)
{
	int		y;
	t_draw	d;

	d.line_hegiht = (int)(HEIGHT / r->perpwalldist);
	d.draw_start = -d.line_hegiht / 2 + HEIGHT / 2;
	if (d.draw_start < 0)
		d.draw_start = 0;
	d.draw_end = d.line_hegiht / 2 + HEIGHT / 2;
	if (d.draw_end >= HEIGHT)
		d.draw_end = HEIGHT - 1;
	// texturing calculations texNum으로 벽면 이미지 바꾸는중
	d.tex_num = 1;
	if (r->side == 1)
		d.tex_num = 2;
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
	d.tex_pos = (d.draw_start - HEIGHT / 2 + d.line_hegiht / 2) * d.step;
	y = d.draw_start;
	while (++y < d.draw_end)
	{
		d.tex_y = (int)d.tex_pos & (TEXHEIGHT - 1);
		d.tex_pos += d.step;
		window->buf[y][x] = window->texture[d.tex_num]
		[TEXHEIGHT * d.tex_y + d.tex_x];
	}
}

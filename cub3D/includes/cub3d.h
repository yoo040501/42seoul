/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:59 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/06 15:17:17 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 

# include <stdio.h>
# include "mlx_keycode.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct s_text
{
	int		texture_cnt;
	char	*n_path;
	char	*w_path;
	char	*e_path;
	char	*s_path;
	int		c_color;
	int		f_color;
}t_text;

typedef struct s_map
{
	double	player_x;
	double	player_y;
	double	plane_x;
	double	plane_y;
	int		player_cnt;
	int		player_dir;
	double	dir_x;
	double	dir_y;
}t_map;

typedef struct s_info
{
	char	**map;
	int		map_height;
	int		map_width;
	t_text	*text;
	t_map	map_info;
}t_info;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}t_img;

typedef struct s_key
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_r;
	int		key_l;
	int		mouse_r;
	int		mouse_l;
	int		key_space;
}t_key;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		**texture;
	int		**buf;
	double	camera_height;
	double	move_speed;
	double	rot_speed;
	t_info	*info;
	t_key	key_flag;
	t_img	img;
}t_window;

typedef struct s_raycast
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
}t_raycast;

typedef struct s_draw
{
	int		line_hegiht;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}t_draw;

# define TRUE 1
# define FALSE 0
# define N 0
# define S 1
# define E 2
# define W 3
# define WIDTH 1280
# define HEIGHT 1024
# define TEXWIDTH 64
# define TEXHEIGHT 64

/*	cub3d.c*/
void		print_error(char *str);
int			closed(t_window *window);
/*	check_file.c & check_in_file.c	*/
char		*check_file(char *av);
void		check_in_file(char *map, t_info *info);
/*	check_texture.c	*/
void		get_we_path(char *texture, t_info *info, int *flag);
void		get_so_path(char *texture, t_info *info, int *flag);
void		get_ea_path(char *texture, t_info *info, int *flag);
void		get_no_path(char *texture, t_info *info, int *flag);
char		*cut_nl(char *path);
/*	check_texture_two.c	*/
void		get_c_color(char *color, t_info *info, int *flag);
void		get_f_color(char *color, t_info *info, int *flag);
int			is_dup_texture(t_info *info);
/*	get_map.c	*/
void		get_map(t_info *info, int fd);
void		is_vaild_map(t_info *info);
/*	cal.c	*/
int			key_press(int key, t_window *window);
void		calc(t_window *window);
/*	image.c	*/
void		draw(t_window *window);
void		load_texture(t_window *window);
/*	key.c	*/
int			key_release(int key, t_window *window);
int			key_press(int key, t_window *window);
void		key_move(t_window *window);
/*	key_move.c	*/
void		key_rotate_l(t_window *window, t_map *map);
void		key_rotate_r(t_window *window, t_map *map);
void		key_move_updown(t_window *window, t_map *map, char **worldmap);
void		key_move_rl(t_window *window, t_map *map, char **worldmap);
void		key_space(t_window *window);
/*	mouse.c	*/
void		mouse_move(t_window *window);
int			check_mouse(int x, int y, t_window *window);
/*	save_buffer.c	*/
void		save_wall(t_window *window, t_map *info, t_raycast *r, int x);
/*	free.c	*/
void		free_info(t_info *info);
void		ft_free_2d(void **str);
void		ft_free(void **target);
void		free_window(t_window *window);
/*	init.c	*/
t_info		*info_init(void);
t_window	*window_init(t_info *info);

#endif

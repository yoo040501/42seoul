/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:59 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/25 14:14:56 by dongeunk         ###   ########.fr       */
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

typedef struct s_text
{
	int		texture_cnt;
	char	*n_path;
	char	*w_path;
	char	*e_path;
	char	*s_path;
	char	*c_color;
	char	*f_color;
}t_text;

typedef struct s_map
{
	double	player_x;
	double	player_y;
	double	plane_x;
	double	plane_y;
	int		player_cnt;
	int		player_dir;

}t_map;

typedef struct s_info
{
	char	**map;
	int		height;
	int		width;
	t_text	*text;
	t_map	map_info;
}t_info;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	void	*n_wall;
	void	*w_wall;
	void	*e_wall;
	void	*s_wall;
	int		width;
	int		height;
	t_info	*info;
}t_window;

# define TRUE 1
# define FALSE 0
# define N 1
# define S 2
# define E 3
# define W 4	

void		print_error(char *str);

char		*check_file(char *av);
void		check_in_file(char *map, t_info *info);

t_info		*info_init(void);
t_window	*window_init(t_info *info);

void		get_we_path(char *texture, t_info *info, int *flag);
void		get_so_path(char *texture, t_info *info, int *flag);
void		get_ea_path(char *texture, t_info *info, int *flag);
void		get_no_path(char *texture, t_info *info, int *flag);

void		get_c_color(char *color, t_info *info, int *flag);
void		get_f_color(char *color, t_info *info, int *flag);
int			is_dup_texture(t_info *info);
char		*cut_nl(char *path);

void		get_map(t_info *info, int fd);
void		is_vaild_map(t_info *info);

void		free_info(t_info *info);
void		ft_free_2d(char **str);
void		ft_free(void **target);

#endif

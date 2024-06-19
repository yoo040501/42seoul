/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:15:06 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/05 17:03:48 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "mlx_keycode.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*cat;
	void	*wall;
	void	*road;
	void	*coin;
	void	*door;
	void	*open;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		x_max;
	int		y_max;
	int		cnt;
	int		player;
	int		out;
	int		coin_cnt;
}t_vars;

int		closed(t_vars *vars);

void	check_map(t_vars *vars);
char	**get_map(void);
void	check_components(char **map, t_vars *vars);
void	check_wall(char **map);
void	check_line(char **map);

void	move_r(t_vars *vars, int x, int y);
void	move_l(t_vars *vars, int x, int y);
void	move_d(t_vars *vars, int x, int y);
void	move_u(t_vars *vars, int x, int y);
void	check_coin(t_vars *vars);

void	draw_win(t_vars *vars);
void	check_exit(t_vars *vars, char flag);
void	put_image(t_vars *vars, void *id, int x, int y);
void	print_error(char *str);

#endif

#include "../../includes/cub3d.h"

void	mouse_move(t_window *window)
{
	double	olddir_x;
	double	oldplane_x;
	double	rot_speed;
	t_map	*map;

	rot_speed = window->rot_speed - 0.02;
	map = &window->info->map_info;
	if (window->key_flag.mouse_l == 1)
	{
		olddir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(-rot_speed)
			- map->dir_y * sin(-rot_speed);
		map->dir_y = olddir_x * sin(-rot_speed)
			+ map->dir_y * cos(-rot_speed);
		oldplane_x = map->plane_x;
		map->plane_x = map->plane_x * cos(-rot_speed)
			- map->plane_y * sin(-rot_speed);
		map->plane_y = oldplane_x * sin(-rot_speed)
			+ map->plane_y * cos(-rot_speed);
	}
	if (window->key_flag.mouse_r == 1)
	{
		olddir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(rot_speed)
			- map->dir_y * sin(rot_speed);
		map->dir_y = olddir_x * sin(rot_speed)
			+ map->dir_y * cos(rot_speed);
		oldplane_x = map->plane_x;
		map->plane_x = map->plane_x * cos(rot_speed)
			- map->plane_y * sin(rot_speed);
		map->plane_y = oldplane_x * sin(rot_speed)
			+ map->plane_y * cos(rot_speed);	
	}
}

int	check_mouse(int x, int y, t_window *window)
{
	if (y >= 0 && y <= HEIGHT)
	{
		if (x >= 0 && x <= WIDTH * 6 / 16)
		{
			window->key_flag.mouse_l = 1;
			window->key_flag.mouse_r = 0;	
		}
		else if (x <= WIDTH && x >= WIDTH * 10 / 16)
		{
			window->key_flag.mouse_l = 0;
			window->key_flag.mouse_r = 1;
		}
		else
		{
			window->key_flag.mouse_l = 0;
			window->key_flag.mouse_r = 0;
		}
	}
	return (0);
}

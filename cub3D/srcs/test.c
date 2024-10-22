#include "../includes/cub3d.h"
#include "../includes/mlx_keycode.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

int main(void)
{
	char *str;
	int fd;

	fd = open("map/test1.cub", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf ("str: %s", str);
		if (str[0] == '\n')
			printf("aaa");
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	close(fd);
	fd = open("map/test1.cub", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf ("str: %s", str);
		if (str[0] == '\n')
			printf("bbb");
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	close(fd);
	return 0;
}
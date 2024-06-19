#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int fd;
	int	fd2, fd3;

	fd = open("get_next_line.h", O_RDONLY);
	char *a = get_next_line(fd);
	printf("fd :%d\n%s",fd, a);
	close(fd);
	char	*b = get_next_line(fd);
	printf("fd:%d\n%s",fd, b);
	fd2 = open("get_next_line.h", O_RDONLY);
	char *c = get_next_line(fd2);
	printf("fd:%d\n%s",fd2, c);
}

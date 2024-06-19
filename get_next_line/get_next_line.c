/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:03:44 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 15:24:34 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*get_next_line2(int fd, char *buf, char **save);
char	*find_next(char **save, char *buf);
char	*find_eof(char **save, char *buf);

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*save;

	if (fd == -1 || BUFFER_SIZE < 1)
		return ((void *)0);
	buf = gnl_malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		if (save)
			return (gnl_free((void *)0, &save));
		return ((void *)0);
	}
	if (!save)
		save = gnl_malloc(BUFFER_SIZE + 1);
	if (!save)
		return (gnl_free((void *)0, &buf));
	if (read(fd, buf, 0) < 0)
		return (gnl_free(buf, &save));
	return (get_next_line2(fd, buf, &save));
}

char	*get_next_line2(int fd, char *buf, char **save)
{
	t_list	box;

	box.i = 1;
	while (gnl_strchr_cat(save, '\n', buf) == 0)
	{
		box.read_size = read(fd, buf, BUFFER_SIZE);
		if (box.read_size < 0)
			return (gnl_free(buf, save));
		buf[box.read_size] = '\0';
		if (box.read_size == 0)
			return (find_eof(save, buf));
		if (gnl_strlen(*save) + BUFFER_SIZE >= (BUFFER_SIZE * box.i))
		{
			if (gnl_strlen(*save) + BUFFER_SIZE <= 2147483647)
				box.i *= 2;
			box.temp = (*save);
			(*save) = gnl_malloc((BUFFER_SIZE * box.i) + 1);
			if (!(*save))
				return (gnl_free(buf, &box.temp));
			(*save) = gnl_strchr_cat(save, -1, box.temp);
			gnl_free((void *)0, &box.temp);
		}
		(*save) = gnl_strchr_cat(save, -1, buf);
	}
	return (find_next(save, buf));
}

char	*find_eof(char **save, char *buf)
{
	t_list	box;

	box.i = gnl_strlen(*save);
	if (box.i == 0)
		return (gnl_free(buf, save));
	box.line = gnl_malloc(box.i + 1);
	if (!box.line)
		return (gnl_free(buf, save));
	box.line = gnl_strchr_cat(&box.line, -1, *save);
	gnl_free(buf, save);
	return (box.line);
}

char	*find_next(char **save, char *buf)
{
	t_list	box;

	box.i = 0;
	box.idx = 0;
	while ((*save)[box.idx] != '\n')
		box.idx++;
	box.line = gnl_malloc(box.idx + 2);
	if (!box.line)
		return (gnl_free(buf, save));
	while (box.i < box.idx + 1)
		box.line[box.i] = (*save)[box.i++];
	box.line[box.i] = '\0';
	box.temp = (*save);
	box.i = gnl_strlen((*save) + box.idx + 1);
	(*save) = gnl_malloc(box.i + 1);
	if (!(*save))
	{
		gnl_free(buf, &box.temp);
		return (gnl_free((void *)0, &box.line));
	}
	(*save) = gnl_strchr_cat(save, -1, box.temp + box.idx + 1);
	gnl_free(buf, &box.temp);
	return (box.line);
}

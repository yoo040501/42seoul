/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:00:59 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 12:54:30 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_save
{
	char			*save;
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_save	*next;
}	t_save;

typedef struct s_list
{
	char	*line;
	char	*temp;
	ssize_t	read_size;
	ssize_t	i;
	ssize_t	idx;
}	t_list;

char	*get_next_line(int fd);
ssize_t	gnl_strlen(const char *str);
char	*gnl_strchr_cat(char **dest, int c, char *src);
char	*free_or_malloc(char **save, int len);
char	*free_node(t_save **head, int fd, char *str);
t_save	*find_fd(t_save *node, int fd);
#endif

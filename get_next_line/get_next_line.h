/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:13:22 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 13:43:27 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
	char	*line;
	char	*temp;
	size_t	read_size;
	size_t	i;
	size_t	idx;
}	t_list;

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr_cat(char **dest, int c, char *src);
char	*gnl_malloc(int len);
char	*gnl_free(char *str, char **save);
#endif

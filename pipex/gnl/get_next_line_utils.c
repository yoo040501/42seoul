/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:39:53 by dongeunk          #+#    #+#             */
/*   Updated: 2024/02/26 12:56:06 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr_cat(char **s, int c, char *src);
ssize_t	gnl_strlen(const char *str);
char	*free_node(t_save **head, int fd, char *str);
char	*free_or_malloc(char **save, int len);
t_save	*find_fd(t_save *node, int fd);

char	*gnl_strchr_cat(char **dest, int c, char *src)
{
	int	i;
	int	len;

	if (c == -1)
	{
		i = gnl_strlen(*dest);
		while (*src)
			(*dest)[i++] = *src++;
		(*dest)[i] = '\0';
		return (*dest);
	}
	if (!(*dest))
		return ((void *)0);
	i = 0;
	len = gnl_strlen((*dest));
	while (i <= len)
	{
		if ((*dest)[i] == (char)c)
			return ((char *)((*dest) + i));
		i++;
	}
	return ((void *)0);
}

ssize_t	gnl_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*free_node(t_save **head, int fd, char *str)
{
	t_save	*temp;
	t_save	*first_node;

	if (str)
		free_or_malloc(&str, 0);
	if ((*head)->fd == fd)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		first_node = *head;
		temp = find_fd(*head, fd);
		while ((*head)->next->fd != fd)
			*head = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(temp);
		*head = first_node;
	}
	return ((void *)0);
}

char	*free_or_malloc(char **save, int len)
{
	char	*temp;

	if (len == 0)
	{
		free(*save);
		(*save) = ((void *)0);
		return ((void *)0);
	}
	temp = (char *)malloc(sizeof(char) * len);
	if (!temp)
		return ((void *)0);
	temp[0] = '\0';
	return (temp);
}

t_save	*find_fd(t_save *node, int fd)
{
	if (!(node))
		return ((void *)0);
	while (node)
	{
		if (node->fd == fd)
			return (node);
		(node) = (node)->next;
	}
	return ((void *)0);
}

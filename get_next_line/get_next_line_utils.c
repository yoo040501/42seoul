/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:14:02 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 13:43:37 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr_cat(char **s, int c, char *src);
size_t	gnl_strlen(const char *str);
char	*gnl_free(char *str, char **save);
char	*gnl_malloc(int len);

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

size_t	gnl_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_free(char *str, char **save)
{
	if (str)
	{
		free(str);
		str = ((void *)0);
	}
	free(*save);
	(*save) = ((void *)0);
	return ((void *)0);
}

char	*gnl_malloc(int len)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * len);
	if (!temp)
		return ((void *)0);
	temp[0] = '\0';
	return (temp);
}

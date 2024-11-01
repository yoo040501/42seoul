/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:20:27 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/01 12:56:52 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*word;
	int		start;
	int		end;

	if (!s1 || !set)
		return ((void *)0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return ((void *)0);
	ft_strlcpy(word, &s1[start], end - start + 1);
	return (word);
}

char	*ft_strtrim_free(char *s1, char const *set)
{
	char	*word;
	int		start;
	int		end;

	if (!s1 || !set)
		return ((void *)0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return ((void *)0);
	ft_strlcpy(word, &s1[start], end - start + 1);
	free(s1);
	s1 = 0;
	return (word);
}

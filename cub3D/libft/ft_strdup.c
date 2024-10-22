/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:16:18 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/02 14:43:36 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(char *s1);
static void	ft_strcpy(char *dest, char *src);

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dest;
	char	*src;

	src = (char *)s1;
	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

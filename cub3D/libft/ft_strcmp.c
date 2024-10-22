/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:16:18 by dongeunk          #+#    #+#             */
/*   Updated: 2024/10/02 15:19:16 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((*(a + i) || *(b + i)))
	{
		if (*(a + i) < *(b + i))
			return (*(a + i) - *(b + i));
		else if (*(a + i) > *(b + i))
			return (*(a + i) - *(b + i));
		i++;
	}
	return (0);
}

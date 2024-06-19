/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:29:27 by dongeunk          #+#    #+#             */
/*   Updated: 2023/08/30 23:36:18 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(dest + i))
		i++;
	while (*src && j < nb)
	{
		*(dest + i) = *src;
		i++;
		src++;
		j++;
	}
	*(dest + i) = '\0';
	return (dest);
}

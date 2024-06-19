/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:02:09 by dongeunk          #+#    #+#             */
/*   Updated: 2023/08/31 11:19:03 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (*(src + len))
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	ret;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (src_len + size);
	ret = src_len + dest_len;
	while (*src && dest_len + 1 < size)
	{
		*(dest + dest_len) = *src;
		dest_len++;
		src++;
	}
	*(dest + dest_len) = '\0';
	return (ret);
}

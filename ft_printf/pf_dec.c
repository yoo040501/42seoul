/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:26:53 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/24 16:39:45 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_getlen(ssize_t n)
{
	ssize_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	pf_putint(int n)
{
	ssize_t	len;
	ssize_t	cnt;
	ssize_t	i;
	char	num;

	if (n < 0)
	{
		n *= -1;
		write (1, "-", 1);
	}
	len = pf_getlen(n);
	while (len)
	{
		cnt = len - 1;
		i = 1;
		while (cnt--)
			i *= 10;
		num = (n / i) + '0';
		write (1, &num, 1);
		n %= i;
		len--;
	}
}

void	pf_putuint(int n)
{
	ssize_t			len;
	ssize_t			cnt;
	ssize_t			i;
	char			str;
	unsigned int	num;

	num = (unsigned int)n;
	len = pf_getlen(num);
	while (len)
	{
		cnt = len - 1;
		i = 1;
		while (cnt--)
			i *= 10;
		str = (num / i) + '0';
		write (1, &str, 1);
		num %= i;
		len--;
	}
}

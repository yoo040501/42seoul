/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:16:01 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 16:06:38 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_num(size_t cnt, unsigned int n)
{
	char	num;
	int		i;

	i = 1;
	while (cnt--)
		i *= 10;
	num = (n / i) + '0';
	if (write (1, &num, 1) == -1)
		return (-1);
	n %= i;
	return (n);
}

static int	pf_getlen(long n)
{
	size_t	i;

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

int	pf_putuint(unsigned int a, int ret)
{
	size_t	len;
	size_t	cnt;
	long	n;

	n = (long)a;
	len = pf_getlen(n);
	ret = len;
	while (len)
	{
		cnt = len - 1;
		n = write_num(cnt, n);
		if (n == -1)
			return (-1);
		len--;
	}
	return (ret);
}

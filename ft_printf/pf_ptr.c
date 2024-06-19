/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:29:26 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 16:06:04 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	pf_getstr(unsigned long num, unsigned long i)
{
	char	str;

	if ((num / i) < 10)
		str = (num / i) + '0';
	else
		str = (num / i) + 'a' - 10;
	return (str);
}

static unsigned long	pf_getlen(unsigned long num)
{
	unsigned long	cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 16;
		cnt++;
	}
	return (cnt);
}

int	pf_putptr(unsigned long n, int ret)
{
	unsigned long	len;
	unsigned long	cnt;
	unsigned long	i;
	char			str;

	len = pf_getlen(n);
	ret = (int)len + 2;
	if (write (1, "0x", 2) == -1)
		return (-1);
	while (len)
	{
		cnt = len - 1;
		i = 1;
		while (cnt--)
			i *= 16;
		str = pf_getstr(n, i);
		if (write (1, &str, 1) == -1)
			return (-1);
		n %= i;
		len--;
	}
	return (ret);
}

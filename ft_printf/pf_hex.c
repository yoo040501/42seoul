/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:27:13 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 16:04:00 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	pf_getstr(unsigned int num, unsigned int i, char flag)
{
	char	str;

	if ((num / i) < 10)
		str = (num / i) + '0';
	else
	{
		if (flag == 'x')
			str = (num / i) + 'a' - 10;
		else
			str = (num / i) + 'A' - 10;
	}
	return (str);
}

static unsigned int	pf_getlen(unsigned int num)
{
	unsigned int	cnt;

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

int	pf_puthex(unsigned int n, char flag, int ret)
{
	unsigned int	len;
	unsigned int	cnt;
	unsigned int	i;
	char			str;

	len = pf_getlen(n);
	ret = (int)len;
	while (len)
	{
		cnt = len - 1;
		i = 1;
		while (cnt--)
			i *= 16;
		str = pf_getstr(n, i, flag);
		if (write (1, &str, 1) == -1)
			return (-1);
		n %= i;
		len--;
	}
	return (ret);
}

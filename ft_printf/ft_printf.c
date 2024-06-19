/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:18:27 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 16:06:03 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_other(char a)
{
	if (write(1, &a, 1) == -1)
		return (-1);
	return (1);
}

int	check_next(char flag, va_list ap)
{
	int	len;

	if (flag == 's')
		len = pf_putstr(va_arg(ap, char *));
	else if (flag == 'c')
		len = pf_putchr(va_arg(ap, int));
	else if (flag == 'p')
		len = pf_putptr((unsigned long)va_arg(ap, void *), 0);
	else if (flag == 'd' || flag == 'i')
		len = pf_putint(va_arg(ap, int), 0);
	else if (flag == 'u')
		len = pf_putuint(va_arg(ap, unsigned int), 0);
	else if (flag == 'x' || flag == 'X')
		len = pf_puthex(va_arg(ap, unsigned int), flag, 0);
	else if (flag == '%')
		len = pf_putchr('%');
	else
		return (-2);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		idx;
	int		len;
	int		len2;

	va_start(ap, format);
	idx = 0;
	len = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
			len2 = check_next(format[++idx], ap);
		else
			len2 = write_other(format[idx]);
		if (len2 == -1 || len2 == -2)
		{
			if (len2 == -1)
				len = -1;
			break ;
		}
		len += len2;
		idx++;
	}
	va_end(ap);
	return (len);
}

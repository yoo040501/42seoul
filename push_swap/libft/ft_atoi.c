/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:16:50 by dongeunk          #+#    #+#             */
/*   Updated: 2024/02/19 11:23:27 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long				ft_atoi(char *str);
static long long		ft_getint(char *s, int si);

long long	ft_atoi(char *str)
{
	int				si;
	long long		ret;
	char			*s;

	s = (char *)str;
	si = 1;
	while ((*s == ' ') || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			si *= -1;
		s++;
	}
	if (*s < '0' || *s > '9')
		return (print_error());
	ret = ft_getint(s, si);
	return ((ret * si));
}

static long long	ft_getint(char *s, int si)
{
	unsigned long	ret;
	int				cnt;

	cnt = 0;
	ret = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (print_error());
		if (cnt > 10)
			return (print_error());
		if (!(cnt == 0 && *s == '0'))
			cnt++;
		ret = ret * 10 + *(s++) - '0';
		if ((si == 1) && ret > 9223372036854775807)
			return (-1);
		if ((si == -1) && ret > 9223372036854775808U)
			return (0);
	}
	return (ret);
}

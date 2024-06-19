/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:23:50 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/11 18:37:49 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_change_base(char *str, char *base, int l_s, int l_b)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[l_s])
	{
		i = 0;
		while (base[i])
		{
			if (base[i] == str[l_s])
				break ;
			i++;
		}
		if (i >= l_b)
			break ;
		ret *= l_b;
		ret += i;
		l_s++;
	}
	return (ret);
}

int	ft_check_str(char *str, int l_s)
{
	int	sign;

	sign = 1;
	while ((*(str + l_s) == ' ') || (*(str + l_s) >= 9 && *(str + l_s) <= 13))
		l_s++;
	while (*(str + l_s) == '+' || *(str + l_s) == '-')
	{
		if (*(str + l_s) == '-')
			sign *= -1;
		l_s++;
	}
	return (sign);
}

int	ft_check_base(char *base, int i, int first)
{
	int	second;

	while (*(base + i))
	{
		if ((*(base + i) == ' ') || (*(base + i) >= 9 && *(base + i) <= 13))
			return (0);
		if (*(base + i) == '-' || *(base + i) == '+')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	while (first < i - 1)
	{
		second = first + 1;
		while (second < i)
		{
			if (*(base + first) == *(base + second))
				return (0);
			second++;
		}
		first++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	l_b;
	int	l_s;
	int	sign;

	l_b = 0;
	l_s = 0;
	if (!ft_check_base(base, 0, 0))
		return (0);
	sign = ft_check_str(str, l_s);
	while (*(base + l_b))
		l_b++;
	while ((*(str + l_s) == ' ') || (*(str + l_s) >= 9 && *(str + l_s) <= 13))
		l_s++;
	while (*(str + l_s) == '+' || *(str + l_s) == '-')
	{
		l_s++;
	}
	return (ft_change_base(str, base, l_s, l_b) * sign);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base(" 2147483648", "0123456789"));
}

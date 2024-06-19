/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:29:31 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/06 17:12:54 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_get_len(char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
		i++;
	return (i);
}

void	ft_change_base(int nbr, char *base, int len)
{
	unsigned int	n;

	n = (unsigned int)nbr;
	if (nbr < 0)
	{
		n = (unsigned int)(nbr * -1);
		write(1, "-", 1);
	}
	if (n >= (unsigned int)len)
	{
		ft_change_base(n / len, base, len);
		write(1, &base[(n % len)], 1);
	}
	else
		write(1, &base[n], 1);
}

int	ft_check_base(char *base, int i, int first)
{
	int	second;

	while (*(base + i))
	{
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	flag;
	int	len;

	flag = ft_check_base(base, 0, 0);
	if (!flag)
		return ;
	len = ft_get_len(base);
	ft_change_base(nbr, base, len);
}

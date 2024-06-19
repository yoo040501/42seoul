/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:43:04 by dongeunk          #+#    #+#             */
/*   Updated: 2023/08/30 21:21:01 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char str)
{
	write(1, &str, 1);
}

void	ft_putchange(unsigned char *arr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		*(arr + i) = i + '0';
		if (i >= 10)
			*(arr + i) = i + 87;
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	word;
	unsigned char	change[16];

	ft_putchange(change);
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
		{
			word = (unsigned char)*str;
			ft_putchar('\\');
			ft_putchar(change[word / 16]);
			ft_putchar(change[word % 16]);
		}
		else
			write(1, str, 1);
		str++;
	}
}

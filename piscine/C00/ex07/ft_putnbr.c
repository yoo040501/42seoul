/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:48:21 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/06 12:45:32 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	num;

	if (nb == -2147483648)
		write(1, &"-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, &"-", 1);
			ft_putnbr(nb);
		}
		else if (nb < 10)
		{
			num = nb % 10 + '0';
			write(1, &num, 1);
		}
		else
		{
			num = nb % 10 + '0';
			nb /= 10;
			ft_putnbr(nb);
			write(1, &num, 1);
		}
	}
}

int main(void)
{
	ft_putnbr(-0);
}

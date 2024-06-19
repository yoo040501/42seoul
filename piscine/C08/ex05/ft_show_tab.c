/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:43:45 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/11 11:10:36 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		write(1, str + i, 1);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	char	num;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	num = nbr % 10 + '0';
	write(1, &num, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
/*int	main(void)
{
	t_stock_str	*arr;
	char	*str[] = {"Hello", "asdE", " asd ee"};
	arr = ft_strs_to_tab(3, str);
	ft_show_tab(arr);
}*/

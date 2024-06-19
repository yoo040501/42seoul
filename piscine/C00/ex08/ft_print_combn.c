/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:30:10 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/13 18:25:48 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn2(int *arr,int n,int cur_index)
{
	int	i;
	int	num;

	i = 0;
	if (cur_index == n - 1)
	{
		while (i < n)
		{
			ft_putchar(arr[i]);
			i++;
		}
		if (arr[0] != 10 - n)
			write(1, ", ", 2);
	}
	if (cur_index == 0)
		num = 0;
}

void	ft_print_combn(int n)
{
	int	arr[9];
	ft_print_combn2(arr, n, 0);
}

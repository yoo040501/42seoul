/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:23:23 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/07 22:20:26 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_mkqueen(int *arr, int cur_i, int *cnt);
int		ft_checking(int *arr, int cur_i);
int		ft_abs(int n, int m);
void	ft_put(char c);

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 10)
	{
		arr[i] = 0;
		i++;
	}
	ft_mkqueen(arr, 0, &cnt);
	return (cnt);
}

void	ft_mkqueen(int *arr, int cur_i, int *cnt)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	if (cur_i == 10)
	{
		while (k < 10)
		{
			ft_put((char)arr[k] + '0');
			k++;
		}
		write(1, "\n", 1);
		*cnt += 1;
		return ;
	}
	while (j < 10)
	{
		arr[cur_i] = j;
		if (ft_checking(arr, cur_i) == 1)
			ft_mkqueen(arr, cur_i + 1, cnt);
		j++;
	}
}

int	ft_checking(int	*arr, int cur_i)
{
	int	i;

	i = 0;
	while (i < cur_i)
	{
		if ((arr[i] == arr[cur_i]) || (cur_i - i == ft_abs(arr[cur_i], arr[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_abs(int n, int m)
{
	if (n > m)
		return (n - m);
	else
		return (m - n);
}

void	ft_put(char c)
{
	write(1, &c, 1);
}

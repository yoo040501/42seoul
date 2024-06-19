/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:58:33 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/07 10:57:09 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = a[0];
	a[0] = b[0];
	b[0] = temp;
	temp = a[1];
	a[1] = b[1];
	b[1] = temp;
}

void	quicksort(int **data, int start, int end, int mode)
{
	int	key;
	int	i;
	int	j;

	key = start;
	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && data[i][mode] <= data[key][mode])
			i++;
		while (j > start && data[j][mode] >= data[key][mode])
			j--;
		if (i > j)
			swap(data[j], data[key]);
		else
			swap(data[j], data[i]);
	}
	quicksort(data, start, j - 1, mode);
	quicksort(data, j + 1, end, mode);
}

int	check_dup_sort(int **pair, int size)
{
	int	i;

		i = 0;
	quicksort(pair, 0, size - 1, 0);
	while (i < size - 1)
	{
		if (pair[i][0] == pair[i + 1][0])
			return (print_error());
		i++;
	}
	i = -1;
	while (++i < size)
		pair[i][0] = i;
	quicksort(pair, 0, size - 1, 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:44:22 by dongeunk          #+#    #+#             */
/*   Updated: 2023/08/28 17:05:31 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	first;
	int	second;
	int	min;

	first = 0;
	while (first < size -1)
	{
		second = first + 1;
		min = tab[first];
		while (second < size)
		{
			if (tab[second] < min)
			{
				min = tab[second];
				tab[second] = tab[first];
				tab[first] = min;
			}
			second++;
		}
		first++;
	}
}

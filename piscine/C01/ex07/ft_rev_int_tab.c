/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:29:32 by dongeunk          #+#    #+#             */
/*   Updated: 2023/08/28 13:43:43 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	middle;

	middle = size / 2;
	i = 0;
	while (i < middle)
	{
		temp = tab[i];
		tab[i] = tab[size -1];
		tab[size -1] = temp;
		i++;
		size--;
	}
}

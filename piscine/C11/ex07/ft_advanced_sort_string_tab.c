/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:54:15 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/14 15:37:01 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		first;
	int		second;
	char	*temp;

	first = 0;
	while (tab[first + 1])
	{
		second = first + 1;
		while (tab[second])
		{
			if (cmp(tab[first], tab[second]) > 0)
			{
				temp = tab[first];
				tab[first] = tab[second];
				tab[second] = temp;
			}
			second++;
		}
		first++;
	}
}

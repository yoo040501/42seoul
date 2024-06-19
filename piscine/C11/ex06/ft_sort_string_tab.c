/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:53:26 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/14 17:24:45 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[first], tab[second]) > 0)
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

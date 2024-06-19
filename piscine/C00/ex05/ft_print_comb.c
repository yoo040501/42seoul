/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:32:42 by dongeunk          #+#    #+#             */
/*   Updated: 2023/08/28 10:56:01 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	word1;
	char	word2;
	char	word3;

	word1 = '0';
	while (word1 <= '7')
	{
		word2 = word1 + 1;
		while (word2 <= '8')
		{
			word3 = word2 + 1;
			while (word3 <= '9')
			{
				write(1, &word1, 1);
				write(1, &word2, 1);
				write(1, &word3, 1);
				if (word1 != '7')
					write(1, &", ", 2);
				word3++;
			}
			word2++;
		}
		word1++;
	}
}

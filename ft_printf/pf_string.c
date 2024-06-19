/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:12:29 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/25 17:31:19 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr(char *word)
{
	int	i;

	if (!word)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (word[i])
		if (write(1, &word[i++], 1) == -1)
			return (-1);
	return (i);
}

int	pf_putchr(int n)
{
	char	word;

	word = (char)n;
	if (write(1, &word, 1) == -1)
		return (-1);
	return (1);
}

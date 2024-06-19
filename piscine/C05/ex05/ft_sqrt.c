/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:57:42 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/08 16:52:11 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned long long	i;

	i = 2;
	if (nb < 1)
		return (0);
	if (nb == 1)
		return (1);
	while (i * i <= (unsigned long long)nb)
	{
		if ((unsigned long long)nb % i == 0 && (unsigned long long)nb / i == i)
			return (i);
		i++;
	}
	return (0);
}

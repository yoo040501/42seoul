/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:09:29 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/08 16:54:52 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned long long	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i * i <= (unsigned long long)nb)
	{
		if ((unsigned long long)nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

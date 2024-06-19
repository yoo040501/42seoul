/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:23:22 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/07 19:46:09 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	unsigned long long	ret;

	ret = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
	{
		ret *= nb;
		if (nb > 1)
			return (ret * ft_recursive_factorial(nb - 1));
	}
	return (ret);
}

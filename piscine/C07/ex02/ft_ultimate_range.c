/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:46:08 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/12 17:14:19 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	num;
	int	*ran;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	ran = (int *)malloc(sizeof(int) * (max - min));
	if (!ran)
		return (-1);
	i = 0;
	num = min;
	while (i < (max - min))
	{
		ran[i] = num;
		i++;
		num++;
	}
	*range = ran;
	return (i);
}

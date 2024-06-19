/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:42:33 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/12 17:10:01 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ran;
	int	i;
	int	num;

	if (min >= max)
		return (0);
	ran = (int *)malloc(sizeof(int) * (max - min));
	if (!ran)
		return (0);
	i = 0;
	num = min;
	while (i < (max - min))
	{
		ran[i] = num;
		i++;
		num++;
	}
	return (ran);
}
/*#include <stdio.h>
int	main(void)
{
	int	*arr;
	arr = ft_range(23, 10);
	printf("%p", arr);
	for(int i=0;i<14;i++)
		printf("%d ",arr[i]);
}*/

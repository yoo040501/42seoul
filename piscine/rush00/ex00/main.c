/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:50:04 by dongeunk          #+#    #+#             */
/*   Updated: 2023/08/25 23:02:06 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	rush_cal(int i, int j, int x, int y)
{
	int	ret;

	ret = 0;
	if (i == 0)
	{
		ret |= 1 << 2;
	}
	else if (i == x - 1)
	{
		ret |= 1 << 3;
	}
	if (j == 0)
	{
		ret |= 1;
	}
	else if (j == y - 1)
	{
		ret |= 1 << 1;
	}
	return (ret);
}

char	run_templete(int index, int rush_num)
{
	const char	*templete[] = {" oooo||--", " /\\\\/****", " ACACBBBB", " AACCBBBB", " ACCABBBB"};
	const int	map[] = {0, 5, 6, -1, 7, 1, 3, -1, 8, 2, 4};
	
	return templete[rush_num][map[index]];
}

void	rush04(int x, int y)
{
	int	i;
	int j;
	int k;
	
	k = 0;
	i = 0;
	while (k < 5)
	{
		putchar(k+'0');
		putchar('\n');
		i = 0;
		while (i < x)
		{
			j = 0;
			while (j < y)
			{	
				putchar(run_templete(rush_cal(i, j, x, y), k));
				j++;
			}
			putchar('\n');
			i++;
		}
		k++;
	}
	return ;
}

int	main(void)
{
	rush04(1,1);
	return (0);
}

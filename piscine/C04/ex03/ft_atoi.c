/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:06:58 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/04 13:05:10 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_getint(char *str, int i, int ret)
{
	while (*(str + i))
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
		{
			ret *= 10;
			ret += *(str + i) - '0';
		}
		else
			break ;
		i++;
	}
	return (ret);
}

int	ft_atoi(char *str)
{
	int	i;
	int	si;
	int	ret;

	i = 0;
	si = 1;
	ret = 0;
	while ((*(str + i) == ' ') || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	while (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			si *= -1;
		i++;
	}
	ret = ft_getint(str, i, ret);
	return (ret * si);
}

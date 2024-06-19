/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:46:49 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/12 14:09:33 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_len(char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
		i++;
	return (i);
}

int	ft_check_base(char *base, int i, int first)
{
	int	second;

	while (*(base + i))
	{
		if ((*(base + i) == ' ') || (*(base + i) >= 9 && *(base + i) <= 13))
			return (0);
		if (*(base + i) == '-' || *(base + i) == '+')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	while (first < i - 1)
	{
		second = first + 1;
		while (second < i)
		{
			if (*(base + first) == *(base + second))
				return (0);
			second++;
		}
		first++;
	}
	return (1);
}

int	ft_check_str(char *str, int *l_s)
{
	int	sign;

	sign = 1;
	while ((*(str + *l_s) == ' ')
		|| (*(str + *l_s) >= 9 && *(str + *l_s) <= 13))
		*l_s += 1;
	while (*(str + *l_s) == '+' || *(str + *l_s) == '-')
	{
		if (*(str + *l_s) == '-')
			sign *= -1;
		*l_s += 1;
	}
	return (sign);
}

int	ft_num_len(int nbr, int len)
{
	int	cnt;

	cnt = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		cnt++;
	while (nbr != 0)
	{
		cnt++;
		nbr /= len;
	}
	return (cnt);
}

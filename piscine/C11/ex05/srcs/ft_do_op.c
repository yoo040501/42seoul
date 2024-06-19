/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:43:35 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/14 17:22:39 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_bool	ft_check_op(char *op);
int		ft_get_op(char *av, char *op);

void	ft_do_op(char **av)
{
	int		num[2];
	char	*op;
	int		i;

	num[0] = ft_atoi(av[1]);
	num[1] = ft_atoi(av[3]);
	op = "+-/*%";
	if (!ft_check_op(av[2]))
	{
		ft_putnbr(0);
		return ;
	}
	i = ft_get_op(av[2], op);
	if (num[1] == 0 && i == 2)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	if (num[1] == 0 && i == 4)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	ft_putnbr(ft_cal(num[0], num[1], i));
}

t_bool	ft_check_op(char *op)
{
	if ((op[0] == '+' || op[0] == '-' || op[0] == '/')
		|| (op[0] == '%' || op[0] == '*') && op[1] == 0)
		return (TRUE);
	return (FALSE);
}

int	ft_get_op(char *av, char *op)
{
	int	i;

	i = 0;
	while (op[i])
	{
		if (op[i] == av[0])
			return (i);
		i++;
	}
	return (0);
}

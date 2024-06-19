/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:41:27 by dongeunk          #+#    #+#             */
/*   Updated: 2024/02/08 13:35:54 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	input_pair(int **pair, int argc, char *argv[])
{
	int		i;
	int		j;
	int		idx;
	char	**str;

	idx = -1;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		str = ft_split(argv[i], ' ');
		while (str[++j])
		{
			pair[++idx][0] = (int)ft_atoi(str[j]);
			pair[idx][1] = idx;
		}
		free_split(str);
	}
}

int	**make_pair(int size, int argc, char *argv[])
{
	int		**pair;
	int		i;

	i = -1;
	pair = (int **)malloc(sizeof(int *) * size);
	if (!pair)
		return (NULL);
	while (++i < size)
	{
		pair[i] = (int *)malloc(sizeof(int) * 2);
		if (!pair[i])
		{
			free_pair(pair, i);
			return (NULL);
		}
	}
	input_pair(pair, argc, argv);
	check_dup_sort(pair, size);
	return (pair);
}

int	check_argv(char **str, int size)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				j++;
			else
				return (print_error());
		}
	}
	i = -1;
	while (str[++i])
	{
		if (ft_atoi(str[i]) < -2147483648 || ft_atoi(str[i]) > 2147483647)
			return (print_error());
		size++;
	}
	return (size);
}

int	input_deque(int argc, char *argv[], t_deque *a)
{
	int		i;
	int		size;
	int		**pair;
	char	**str;

	i = 0;
	size = 0;
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str[0] && i == 1)
		{
			free_split(str);
			exit (0);
		}
		size += check_argv(str, 0);
		free_split(str);
	}
	pair = make_pair(size, argc, argv);
	if (!pair)
		return (print_error());
	push_deq(size, pair, a);
	free_pair(pair, size);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_deque	*a;
	t_deque	*b;
	t_a_b	*all_deq;
	int		stack[2];

	stack[0] = 0;
	stack[1] = 0;
	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_deque));
	b = malloc(sizeof(t_deque));
	all_deq = malloc(sizeof(t_a_b));
	if (!a || !b || !all_deq)
		return (print_error());
	set_deque(a, b);
	input_deque(argc, argv, a);
	set_all_deque(all_deq, a, b);
	if (is_sorted(a))
		exit(0);
	if (a->size > 6)
		sort_a(all_deq, all_deq->a->size, stack);
	else
		sort_all(all_deq, stack);
	print_rule(stack[0]);
	exit(0);
}

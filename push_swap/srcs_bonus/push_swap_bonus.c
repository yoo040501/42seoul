/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:23:31 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/11 17:18:57 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

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

int	make_deq(int argc, char *argv[], t_deque *a)
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
			exit(0);
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
	t_cmd	*head;

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_deque));
	if (!a)
		return (print_error());
	b = malloc(sizeof(t_deque));
	if (!b)
		return (print_error());
	set_deque(a, b);
	make_deq(argc, argv, a);
	head = malloc(sizeof(t_cmd));
	head->str = get_next_line(0);
	head->next = NULL;
	head = save_cmd(head);
	checker(a, b, head);
	exit(0);
}

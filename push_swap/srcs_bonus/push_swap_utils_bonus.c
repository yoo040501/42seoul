/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:34 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/11 17:11:10 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

void	checker(t_deque *a, t_deque *b, t_cmd *head)
{
	while (head)
	{
		if (!check_rule(a, b, head->str))
			print_error();
		head = head->next;
	}
	if (check_deq(a, b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	free_pair(int **pair, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(pair[i]);
	free(pair);
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	set_deque(t_deque *a, t_deque *b)
{
	a->front = NULL;
	a->rear = NULL;
	b->front = NULL;
	b->rear = NULL;
	a->size = 0;
	b->size = 0;
}

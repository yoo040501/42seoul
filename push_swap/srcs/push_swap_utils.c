/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:02:45 by dongeunk          #+#    #+#             */
/*   Updated: 2024/02/08 13:38:34 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_all_deque(t_a_b *all_deq, t_deque *a, t_deque *b)
{
	all_deq->a = a;
	all_deq->b = b;
}

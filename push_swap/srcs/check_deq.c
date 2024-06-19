/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_deq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:49:26 by dongeunk          #+#    #+#             */
/*   Updated: 2024/02/08 13:38:57 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque *a)
{
	t_node	*str;

	str = a->front;
	if (str->num != 0)
		return (0);
	while (str)
	{
		if (str->next)
		{
			if (str->num != str->next->num - 1)
				return (0);
		}
		str = str->next;
	}
	return (1);
}

int	check_b(t_a_b *deq, int push_size, int *stack)
{
	int	cnt;

	cnt = push_size;
	if (push_size < 4)
	{
		while (push_size > 0)
		{
			p('a', deq->a, deq->b, stack);
			push_size--;
		}
		check_a(deq, cnt, stack);
		return (-1);
	}
	if (deq->b->front->num - 1 == deq->a->front->num)
	{
		p('a', deq->a, deq->b, stack);
		push_size--;
	}
	return (push_size);
}

void	check_a(t_a_b *deq, int push_size, int *stack)
{
	t_node	*str;

	str = deq->a->front;
	if (deq->a->size < 4)
		push_size = sort_three_only_a(deq, stack);
	if (push_size == 1)
		return ;
	else if (push_size == 2)
	{
		if (str->num > str->next->num)
			s('a', deq->a, deq->b, stack);
	}
	else if (push_size == 3)
		sort_three_a(deq, stack);
}

int	find_min_num(t_deque *deq, int push_size)
{
	int		min;
	t_node	*size;

	size = deq->front;
	min = deq->front->num;
	while (push_size > 0)
	{
		if (min > size->num)
			min = size->num;
		size = size->next;
		push_size--;
	}
	return (min);
}

int	sort_size_util(t_a_b *deq, int cnt, int flag, int *stack)
{
	cnt += 1;
	if (flag == 1 || flag == 4)
		r_r(deq->a, deq->b, stack);
	else
	{
		if (flag == 0)
			r('a', deq->a, deq->b, stack);
		else
			r('b', deq->a, deq->b, stack);
	}
	return (cnt);
}

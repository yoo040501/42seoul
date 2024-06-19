/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_size_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:11:59 by dongeunk          #+#    #+#             */
/*   Updated: 2024/01/29 17:09:55 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_only_one(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->a->front;
	if (str->next->num > str->next->next->num)
	{
		s('a', deq->a, deq->b, stack);
		rr('a', deq->a, deq->b, stack);
	}
	else
	{
		if (str->num > str->next->next->num)
			r('a', deq->a, deq->b, stack);
		else
			s('a', deq->a, deq->b, stack);
	}
}

void	sort_three_only_two(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->a->front;
	if (str->num > str->next->next->num)
		rr('a', deq->a, deq->b, stack);
	else
	{
		if (str->next->num > str->next->next->num)
		{
			rr('a', deq->a, deq->b, stack);
			s('a', deq->a, deq->b, stack);
		}
	}
}

int	sort_three_only_a(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->a->front;
	if (deq->a->size == 1)
		return (0);
	else if (deq->a->size == 2)
	{
		if (str->num > str->next->num)
			s('a', deq->a, deq->b, stack);
	}
	else
	{
		if (str->num > str->next->num)
			sort_three_only_one(deq, stack);
		else
			sort_three_only_two(deq, stack);
	}
	return (0);
}

void	sort_three_b(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->b->front;
	if (!str || deq->b->size <= 1)
		return ;
	else if (deq->b->size == 2)
	{
		if (str->num < str->next->num)
			s('b', deq->a, deq->b, stack);
	}
	else
	{
		if (str->num < str->next->num)
			sort_three_b_one(deq, stack);
		else
			sort_three_b_two(deq, stack);
	}
}

void	sort_all(t_a_b *deq, int *stack)
{
	int	max_num;

	max_num = deq->a->size - 1;
	while (deq->a->size > 3)
		p('b', deq->a, deq->b, stack);
	sort_three_only_a(deq, stack);
	if (!deq->b->size)
		return ;
	sort_three_b(deq, stack);
	if (deq->a->rear->num == max_num)
		rr('a', deq->a, deq->b, stack);
	else
		p('a', deq->a, deq->b, stack);
	while (deq->b->front || deq->a->rear->num != max_num)
	{
		if (deq->a->rear->num == deq->a->front->num - 1)
			rr('a', deq->a, deq->b, stack);
		else
			p('a', deq->a, deq->b, stack);
	}
}

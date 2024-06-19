/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:10:30 by dongeunk          #+#    #+#             */
/*   Updated: 2024/01/29 17:03:22 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_b_one(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->b->front;
	if (str->next->num < str->next->next->num)
	{
		s('b', deq->a, deq->b, stack);
		rr('b', deq->a, deq->b, stack);
	}
	else
	{
		if (str->num < str->next->next->num)
			r('b', deq->a, deq->b, stack);
		else
			s('b', deq->a, deq->b, stack);
	}
}

void	sort_three_b_two(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->b->front;
	if (str->num < str->next->next->num)
		rr('b', deq->a, deq->b, stack);
	else
	{
		if (str->next->num < str->next->next->num)
		{
			rr('b', deq->a, deq->b, stack);
			s('b', deq->a, deq->b, stack);
		}
	}
}

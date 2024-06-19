/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:44:26 by dongeunk          #+#    #+#             */
/*   Updated: 2024/02/08 13:38:53 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_size(t_a_b *deq, t_pivot *pi, int size, int *stack)
{
	int	ra_flag;

	ra_flag = 3;
	while (++pi->i < size)
	{
		if (deq->b->front->num >= pi->first)
		{
			if (ra_flag == 4)
				r('a', deq->a, deq->b, stack);
			ra_flag = 3;
			pi->pa += p('a', deq->a, deq->b, stack);
			if (deq->a->front->num <= pi->second)
			{
				pi->ra += 1;
				ra_flag = 4;
				if (pi->i == size - 1)
					r('a', deq->a, deq->b, stack);
			}
		}
		else
		{
			pi->rb = sort_size_util(deq, pi->rb, ra_flag, stack);
			ra_flag = 3;
		}
	}
}

void	re_sort_a(t_a_b *deq, int ra, int rb, int *stack)
{
	int	cnt;

	cnt = -1;
	if (ra <= deq->a->size / 2)
	{
		while (++cnt < ra)
			rr_r(deq->a, deq->b, stack);
		while (++cnt <= rb)
			rr('b', deq->a, deq->b, stack);
	}
	else
	{
		while (++cnt < deq->a->size - ra)
			r_r(deq->a, deq->b, stack);
		while (++cnt <= rb)
			r('b', deq->a, deq->b, stack);
	}
}

void	re_sort_b(t_a_b *deq, int ra, int rb, int *stack)
{
	int	cnt;

	cnt = -1;
	if (rb <= deq->b->size / 2)
	{
		while (++cnt < rb)
			rr_r(deq->a, deq->b, stack);
		while (++cnt <= ra)
			rr('a', deq->a, deq->b, stack);
	}
	else
	{
		while (++cnt < deq->b->size - rb)
			r_r(deq->a, deq->b, stack);
		while (++cnt <= ra)
			r('a', deq->a, deq->b, stack);
	}	
}

void	re_sort(t_a_b *deq, int ra, int rb, int *stack)
{
	if (ra >= deq->a->size)
		ra -= deq->a->size;
	if (rb >= deq->b->size)
		rb -= deq->b->size;
	if (ra <= rb)
		re_sort_a(deq, ra, rb, stack);
	else
		re_sort_b(deq, ra, rb, stack);
}

void	sort_a_size(t_a_b *deq, t_pivot *pi, int size, int *stack)
{
	int	rb_flag;

	rb_flag = 0;
	while (++pi->i < size)
	{
		if (deq->a->front->num <= pi->second)
		{
			if (rb_flag == 1)
				r('b', deq->a, deq->b, stack);
			rb_flag = 0;
			pi->pb += p('b', deq->a, deq->b, stack);
			if (deq->b->front->num >= pi->first)
			{
				pi->rb += 1;
				rb_flag = 1;
				if (pi->i == size - 1)
					r('b', deq->a, deq->b, stack);
			}
		}
		else
		{
			pi->ra = sort_size_util(deq, pi->ra, rb_flag, stack);
			rb_flag = 0;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:59 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/07 09:53:53 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a_one(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->a->front;
	if (str->num > str->next->next->num)
	{
		if (str->next->num < str->next->next->num)
		{
			s('a', deq->a, deq->b, stack);
			r('a', deq->a, deq->b, stack);
			s('a', deq->a, deq->b, stack);
			rr('a', deq->a, deq->b, stack);
		}
		else
		{
			s('a', deq->a, deq->b, stack);
			r('a', deq->a, deq->b, stack);
			s('a', deq->a, deq->b, stack);
			rr('a', deq->a, deq->b, stack);
			s('a', deq->a, deq->b, stack);
		}
	}
	else
		s('a', deq->a, deq->b, stack);
}

void	sort_three_a_two(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->a->front;
	if (str->next->num > str->next->next->num)
	{
		if (str->num > str->next->next->num)
		{
			r('a', deq->a, deq->b, stack);
			s('a', deq->a, deq->b, stack);
			rr('a', deq->a, deq->b, stack);
			s('a', deq->a, deq->b, stack);
		}
		else
		{
			r('a', deq->a, deq->b, stack);
			s('a', deq->a, deq->b, stack);
			rr('a', deq->a, deq->b, stack);
		}
	}
}

void	sort_three_a(t_a_b *deq, int *stack)
{
	t_node	*str;

	str = deq->a->front;
	if (str->num > str->next->num)
		sort_three_a_one(deq, stack);
	else
		sort_three_a_two(deq, stack);
}

void	sort_b(t_a_b *deq, int push_size, int *stack)
{
	t_pivot	*pv;
	int		min_num;

	pv = (t_pivot *)malloc(sizeof(t_pivot));
	push_size = check_b(deq, push_size, stack);
	if (push_size == -1)
	{
		free(pv);
		return ;
	}
	min_num = find_min_num(deq->b, push_size);
	pv->i = -1;
	pv->rb = 0;
	pv->ra = 0;
	pv->pa = 0;
	pv->first = push_size / 3 + min_num;
	pv->second = push_size / 3 * 2 + min_num;
	sort_b_size(deq, pv, push_size, stack);
	sort_a(deq, pv->pa - pv->ra, stack);
	re_sort(deq, pv->ra, pv->rb, stack);
	sort_a(deq, pv->ra, stack);
	sort_b(deq, pv->rb, stack);
	free(pv);
}

void	sort_a(t_a_b *deq, int push_size, int *stack)
{
	t_pivot	*pi;
	int		min_num;

	pi = (t_pivot *)malloc(sizeof(t_pivot));
	if (push_size < 4)
	{
		check_a(deq, push_size, stack);
		free(pi);
		return ;
	}
	pi->i = -1;
	pi->pb = 0;
	pi->rb = 0;
	pi->ra = 0;
	min_num = find_min_num(deq->a, push_size);
	pi->first = push_size / 3 + min_num;
	pi->second = push_size / 3 * 2 + min_num;
	sort_a_size(deq, pi, push_size, stack);
	re_sort(deq, pi->ra, pi->rb, stack);
	sort_a(deq, pi->ra, stack);
	sort_b(deq, pi->rb, stack);
	sort_b(deq, pi->pb - pi->rb, stack);
	free(pi);
}

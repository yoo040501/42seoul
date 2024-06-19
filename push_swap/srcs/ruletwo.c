/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruletwo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:07:19 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/07 10:57:29 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_deque *a, t_deque *b, int *stack)
{
	int	save;

	if (!(a->front) || !(a->front->next))
		return ;
	if (!(b->front) || !(b->front->next))
		return ;
	save = a->front->num;
	a->front->num = a->front->next->num;
	a->front->next->num = save;
	save = b->front->num;
	b->front->num = b->front->next->num;
	b->front->next->num = save;
	check_rule(3, stack);
}

void	r_r(t_deque *a, t_deque *b, int *stack)
{
	t_node	*save;

	if (a->front)
	{
		save = a->front;
		push_rear(a, save->num);
		pop_front(a);
	}
	if (b->front)
	{
		save = b->front;
		push_rear(b, save->num);
		pop_front(b);
	}
	check_rule(8, stack);
}

void	rr_r(t_deque *a, t_deque *b, int *stack)
{
	t_node	*save;

	if (a->front)
	{
		save = a->rear;
		push_front(a, save->num);
		pop_rear(a);
	}
	if (b->front)
	{
		save = b->rear;
		push_front(b, save->num);
		pop_rear(b);
	}
	check_rule(11, stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:22:40 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/07 10:57:20 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s(char alp, t_deque *a, t_deque *b, int *stack)
{
	int	save;

	if (alp == 'a')
	{
		if (!(a->front) || !(a->front->next))
			return (0);
		save = a->front->num;
		a->front->num = a->front->next->num;
		a->front->next->num = save;
		check_rule(1, stack);
	}
	else if (alp == 'b')
	{
		if (!(b->front) || !(b->front->next))
			return (0);
		save = b->front->num;
		b->front->num = b->front->next->num;
		b->front->next->num = save;
		check_rule(2, stack);
	}
	return (1);
}

int	p(char alp, t_deque *a, t_deque *b, int *stack)
{
	if (alp == 'a')
	{
		if (!b->front)
			return (0);
		push_front(a, b->front->num);
		pop_front(b);
		check_rule(4, stack);
	}
	else if (alp == 'b')
	{
		if (!(a->front))
			return (0);
		push_front(b, a->front->num);
		pop_front(a);
		check_rule(5, stack);
	}
	return (1);
}

int	r(char alp, t_deque *a, t_deque *b, int *stack)
{
	t_node	*save;

	if (alp == 'a')
	{
		save = a->front;
		push_rear(a, save->num);
		pop_front(a);
		check_rule(6, stack);
	}
	else if (alp == 'b')
	{
		save = b->front;
		push_rear(b, save->num);
		pop_front(b);
		check_rule(7, stack);
	}
	return (1);
}

int	rr(char alp, t_deque *a, t_deque *b, int *stack)
{
	t_node	*save;

	if (alp == 'a')
	{
		save = a->rear;
		push_front(a, save->num);
		pop_rear(a);
		check_rule(9, stack);
	}
	else if (alp == 'b')
	{
		save = b->rear;
		push_front(b, save->num);
		pop_rear(b);
		check_rule(10, stack);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:03 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/07 10:58:08 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	s(char alp, t_deque *a, t_deque *b)
{
	int	save;

	if (alp == 'a')
	{
		if (!(a->front) || !(a->front->next))
			return (0);
		save = a->front->num;
		a->front->num = a->front->next->num;
		a->front->next->num = save;
	}
	else if (alp == 'b')
	{
		if (!(b->front) || !(b->front->next))
			return (0);
		save = b->front->num;
		b->front->num = b->front->next->num;
		b->front->next->num = save;
	}
	return (1);
}

int	p(char alp, t_deque *a, t_deque *b)
{
	if (alp == 'a')
	{
		if (!b->front)
			return (0);
		push_front(a, b->front->num);
		pop_front(b);
	}
	else if (alp == 'b')
	{
		if (!(a->front))
			return (0);
		push_front(b, a->front->num);
		pop_front(a);
	}
	return (1);
}

int	r(char alp, t_deque *a, t_deque *b)
{
	t_node	*save;

	if (alp == 'a')
	{
		if (!a->front)
			return (0);
		save = a->front;
		push_rear(a, save->num);
		pop_front(a);
	}
	else if (alp == 'b')
	{
		if (!b->front)
			return (0);
		save = b->front;
		push_rear(b, save->num);
		pop_front(b);
	}
	return (1);
}

int	rr(char alp, t_deque *a, t_deque *b)
{
	t_node	*save;

	if (alp == 'a')
	{
		if (!a->front)
			return (0);
		save = a->rear;
		push_front(a, save->num);
		pop_rear(a);
	}
	else if (alp == 'b')
	{
		if (!b->front)
			return (0);
		save = b->rear;
		push_front(b, save->num);
		pop_rear(b);
	}
	return (1);
}

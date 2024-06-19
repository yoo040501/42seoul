/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruletwo_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:13 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/07 10:58:13 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_deque *a, t_deque *b)
{
	int	save;

	if (!(a->front) || !(a->front->next))
		return ;
	save = a->front->num;
	a->front->num = a->front->next->num;
	a->front->next->num = save;
	if (!(b->front) || !(b->front->next))
		return ;
	save = b->front->num;
	b->front->num = b->front->next->num;
	b->front->next->num = save;
}

void	r_r(t_deque *a, t_deque *b)
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
}

void	rr_r(t_deque *a, t_deque *b)
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:04:09 by dongeunk          #+#    #+#             */
/*   Updated: 2024/01/18 13:01:51 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_deq(int size, int **pair, t_deque *a)
{
	int	i;

	i = -1;
	while (++i < size)
		push_rear(a, pair[i][0]);
}

int	push_rear(t_deque *deq, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (print_error());
	deq->size++;
	new_node->num = num;
	new_node->idx = deq->size;
	new_node->next = NULL;
	new_node->prev = deq->rear;
	if (!(deq->front))
		deq->front = new_node;
	else
		deq->rear->next = new_node;
	deq->rear = new_node;
	return (0);
}

int	push_front(t_deque *deq, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (print_error());
	new_node->num = num;
	new_node->idx = -1;
	new_node->prev = NULL;
	new_node->next = deq->front;
	if (!(deq->rear))
		deq->rear = new_node;
	else
		deq->front->prev = new_node;
	deq->front = new_node;
	while (new_node)
	{
		new_node->idx++;
		new_node = new_node->next;
	}
	deq->size++;
	return (0);
}

int	pop_rear(t_deque *deq)
{
	t_node	*save;

	if (!(deq->size))
		return (1);
	save = deq->rear->prev;
	free(deq->rear);
	deq->rear = save;
	if (!save)
		deq->front = save;
	save->next = NULL;
	deq->size -= 1;
	if (deq->size < 0)
		deq->size = 0;
	return (0);
}

int	pop_front(t_deque *deq)
{
	t_node	*save;

	if (!(deq->size))
		return (1);
	save = deq->front->next;
	free(deq->front);
	deq->front = save;
	if (!save)
		deq->rear = save;
	deq->size--;
	if (deq->size < 0)
		deq->size = 0;
	while (save)
	{
		save->idx--;
		save = save->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rule_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:57 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/11 17:19:24 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

int	check_deq(t_deque *a, t_deque *b)
{
	t_node	*str;

	if (b->front)
		return (-1);
	str = a->front;
	if (str->num != 0)
		return (-1);
	while (str)
	{
		if (str->next)
		{
			if (str->num != str->next->num - 1)
				return (-1);
		}
		str = str->next;
	}
	return (0);
}

int	check_rule_r(t_deque *a, t_deque *b, char *str)
{
	if (!(str[1] == 'a' || str[1] == 'r' || str[1] == 'b'))
		return (0);
	if (str[1] == 'a' && str[2] == '\n')
		r('a', a, b);
	else if (str[1] == 'b' && str[2] == '\n')
		r('b', a, b);
	else if (str[1] == 'r')
	{
		if (str[2] == 0)
			r_r(a, b);
		else if (str[2] == 'a' && str[3] == '\n')
			rr('a', a, b);
		else if (str[2] == 'b' && str[3] == '\n')
			rr('b', a, b);
		else if (str[2] == 'r' && str[3] == '\n')
			rr_r(a, b);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	check_rule(t_deque *a, t_deque *b, char *str)
{
	if (!(str[0] == 's' || str[0] == 'r' || str[0] == 'p'))
		return (0);
	if (str[0] == 's')
	{
		if (str[1] == 'a' && str[2] == '\n')
			s('a', a, b);
		else if (str[1] == 'b' && str[2] == '\n')
			s('b', a, b);
		else if (str[1] == 's' && str[2] == '\n')
			ss(a, b);
		else
			return (0);
	}
	else if (str[0] == 'r')
		return (check_rule_r(a, b, str));
	else if (str[0] == 'p')
	{
		if (str[1] == 'a' && str[2] == '\n')
			p('a', a, b);
		else if (str[1] == 'b' && str[2] == '\n')
			p('b', a, b);
		else
			return (0);
	}
	return (1);
}

t_cmd	*save_cmd(t_cmd *head)
{
	t_cmd	*str;
	t_cmd	*node;

	node = head;
	if (!(head->str))
	{
		free(head);
		return (NULL);
	}
	while (1)
	{
		str = malloc(sizeof(t_cmd));
		str->str = get_next_line(0);
		if (!(str->str))
		{
			free(str->str);
			free(str);
			break ;
		}
		str->next = NULL;
		while (node->next)
			node = node->next;
		node->next = str;
	}
	return (head);
}

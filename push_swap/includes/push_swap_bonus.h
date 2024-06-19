/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:41:21 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/07 17:50:36 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_deque
{
	int		size;
	t_node	*front;
	t_node	*rear;
}t_deque;

typedef struct s_pivot
{
	int	first;
	int	second;
	int	i;
	int	pb;
	int	pa;
	int	ra;
	int	rb;
}t_pivot;

typedef struct s_cmd
{
	char			*str;
	struct s_cmd	*next;
}t_cmd;

int		push_rear(t_deque *deq, int num);
int		push_front(t_deque *deq, int num);
int		pop_rear(t_deque *deq);
int		pop_front(t_deque *deq);
void	push_deq(int size, int **pair, t_deque *a);

int		p(char alp, t_deque *a, t_deque *b);
int		s(char alp, t_deque *a, t_deque *b);
int		r(char alp, t_deque *a, t_deque *b);
int		rr(char alp, t_deque *a, t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	r_r(t_deque *a, t_deque *b);
void	rr_r(t_deque *a, t_deque *b);

int		print_error(void);
void	free_pair(int **pair, int size);
void	free_split(char **str);
void	set_deque(t_deque *a, t_deque *b);
void	checker(t_deque *a, t_deque *b, t_cmd *head);

void	quicksort(int **data, int start, int end, int mode);
int		check_dup_sort(int **pair, int size);

int		check_rule(t_deque *a, t_deque *b, char *str);
int		check_rule_r(t_deque *a, t_deque *b, char *str);
int		check_deq(t_deque *a, t_deque *b);
t_cmd	*save_cmd(t_cmd *head);

#endif

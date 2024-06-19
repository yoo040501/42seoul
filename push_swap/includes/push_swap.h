/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:37:14 by dongeunk          #+#    #+#             */
/*   Updated: 2024/02/08 13:39:00 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_a_b
{
	t_deque	*a;
	t_deque	*b;
}t_a_b;

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
//deque.c
int		push_rear(t_deque *deq, int num);
int		push_front(t_deque *deq, int num);
int		pop_rear(t_deque *deq);
int		pop_front(t_deque *deq);
void	push_deq(int size, int **pair, t_deque *a);
//Rule,2 .c
int		p(char alp, t_deque *a, t_deque *b, int *stack);
int		s(char alp, t_deque *a, t_deque *b, int *stack);
int		r(char alp, t_deque *a, t_deque *b, int *stack);
int		rr(char alp, t_deque *a, t_deque *b, int *stack);
void	ss(t_deque *a, t_deque *b, int *stack);
void	r_r(t_deque *a, t_deque *b, int *stack);
void	rr_r(t_deque *a, t_deque *b, int *stack);
//push_swap_utils.c
int		print_error(void);
void	free_pair(int **pair, int size);
void	free_split(char **str);
void	set_deque(t_deque *a, t_deque *b);
void	set_all_deque(t_a_b *all_deq, t_deque *a, t_deque *b);
//QuickSort.c
void	quicksort(int **data, int start, int end, int mode);
int		check_dup_sort(int **pair, int size);
//check_deq.c
int		is_sorted(t_deque *a);
void	check_a(t_a_b *all_deq, int push_size, int *stack);
int		check_b(t_a_b *all_deq, int push_size, int *stack);
int		find_min_num(t_deque *deq, int push_size);
int		sort_size_util(t_a_b *all_deq, int cnt, int flag, int *stack);
//three_size_sort.c
int		sort_three_only_a(t_a_b *all_deq, int *stack);
void	sort_three_only_two(t_a_b *all_deq, int *stack);
void	sort_three_only_one(t_a_b *all_deq, int *stack);
void	sort_three_b(t_a_b *all_deq, int *stack);
void	sort_all(t_a_b *all_deq, int *stack);
//mergesort_b.c
void	sort_three_b_two(t_a_b *all_deq, int *stack);
void	sort_three_b_one(t_a_b *all_deq, int *stack);
//greedy.c
void	sort_a(t_a_b *all_deq, int push_size, int *stack);
void	sort_three_a(t_a_b *all_deq, int *stack);
void	sort_b(t_a_b *all_deq, int push_size, int *stack);
void	sort_three_a_two(t_a_b *all_deq, int *stack);
void	sort_three_a_one(t_a_b *all_deq, int *stack);
//greedy_utils.c
void	re_sort(t_a_b *all_deq, int ra, int rb, int *stack);
void	sort_a_size(t_a_b *all_deq, t_pivot *pi, int push_size, int *stack);
void	sort_b_size(t_a_b *all_deq, t_pivot *pi, int push_size, int *stack);
void	sort_a_size(t_a_b *all_deq, t_pivot *pi, int size, int *stack);
void	sort_b_size(t_a_b *all_deq, t_pivot *pi, int size, int *stack);
//print_rule.c
void	save_init(int *save, int size);
void	print_rule(int rule_num);
void	check_rule(int rule_num, int *save);
#endif

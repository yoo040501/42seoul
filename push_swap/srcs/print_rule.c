/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:34:02 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/06 12:17:52 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_init(int *save, int size)
{
	if (size == 1)
	{
		save[0] = save[1];
		save[1] = 0;
	}
	if (size == 2)
	{
		save[0] = 0;
		save[1] = 0;
	}
}

void	print_rule(int rule_num)
{
	if (rule_num == 1)
		write(1, "sa\n", 3);
	else if (rule_num == 2)
		write(1, "sb\n", 3);
	else if (rule_num == 3)
		write(1, "ss\n", 3);
	else if (rule_num == 4)
		write(1, "pa\n", 3);
	else if (rule_num == 5)
		write(1, "pb\n", 3);
	else if (rule_num == 6)
		write(1, "ra\n", 3);
	else if (rule_num == 7)
		write(1, "rb\n", 3);
	else if (rule_num == 8)
		write(1, "rr\n", 3);
	else if (rule_num == 9)
		write(1, "rra\n", 4);
	else if (rule_num == 10)
		write(1, "rrb\n", 4);
	else if (rule_num == 11)
		write(1, "rrr\n", 4);
}

static void	check_rule_three(int *save)
{
	if (save[0] == 9 && save[1] == 10)
	{
		print_rule(11);
		save_init(save, 2);
	}
	else if (save[0] == 10 && save[1] == 9)
	{
		print_rule(11);
		save_init(save, 2);
	}
	else if (save[0] < 12)
	{
		print_rule(save[0]);
		save_init(save, 1);
	}
	if (save[0] == 11 || save [0] == 8 || save[0] == 3)
	{
		print_rule(save[0]);
		save_init(save, 2);
	}
	if (save[1] == 11 || save [1] == 8 || save[1] == 3)
	{
		print_rule(save[1]);
		save_init(save, 1);
	}
}

static void	check_rule_two(int *save)
{
	if (save[0] == 4 || save[0] == 5)
	{
		print_rule(save[0]);
		save_init(save, 1);
	}
	else if (save[0] == 6 && save[1] == 7)
	{
		print_rule(8);
		save_init(save, 2);
	}
	else if (save[0] == 7 && save[1] == 6)
	{
		print_rule(8);
		save_init(save, 2);
	}
	else if (save[0] < 8)
	{
		print_rule(save[0]);
		save_init(save, 1);
	}
	else
		check_rule_three(save);
}

void	check_rule(int rule_num, int *save)
{
	if (save[0] == 0)
		save[0] = rule_num;
	else if (save[1] == 0)
		save[1] = rule_num;
	if (save[1] != 0)
	{
		if (save[0] == 1 && save[1] == 2)
		{
			print_rule(3);
			save_init(save, 2);
		}
		else if (save[0] == 2 && save[1] == 1)
		{
			print_rule(3);
			save_init(save, 2);
		}
		else if (save[0] < 4)
		{
			print_rule(save[0]);
			save_init(save, 1);
		}
		else
			check_rule_two(save);
	}
}

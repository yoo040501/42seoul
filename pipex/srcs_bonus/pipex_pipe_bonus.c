/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:55:03 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/13 15:55:05 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/pipex_bonus.h"

void	make_pipe(t_pipe *pie, int cnt)
{
	int	i;

	pie->fd = malloc(sizeof(int *) * (cnt + 1));
	if (!(pie->fd))
		print_error();
	i = -1;
	while (++i < cnt)
	{
		pie->fd[i] = malloc(sizeof(int) * 2);
		if (!(pie->fd[i]))
			print_error();
		pipe(pie->fd[i]);
	}
}

void	close_pipe(t_pipe *pie)
{
	int	i;

	i = -1;
	while (pie->fd[++i])
	{
		close(pie->fd[i][0]);
		close(pie->fd[i][1]);
	}
}

void	wait_child(int child_process, t_pipe *pie)
{
	int	i;

	i = -1;
	close_pipe(pie);
	while (++i <= child_process)
		wait(0);
}

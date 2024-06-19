/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:52 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/16 11:44:44 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/pipex_bonus.h"
#include "../gnl/get_next_line.h"

void	process_in(char **av, t_pipe *pie, int num)
{
	pie->file = open(av[1], O_RDONLY);
	if (pie->file == -1)
		error();
	if (dup2(pie->file, STDIN_FILENO) == -1)
		error();
	if (dup2(pie->fd[num][1], STDOUT_FILENO) == -1)
		error();
	close(pie->file);
	close_pipe(pie);
	pie->cmd = find_cmd(av[num + 2]);
	find_path(pie->cmd[0], pie);
	if (execve(pie->cmd_path, pie->cmd, NULL) == -1)
		error();
}

void	process_out(char **av, t_pipe *pie, int num)
{
	pie->file = open(av[num + 3], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (pie->file == -1)
		error();
	if (dup2(pie->fd[num - 1][0], STDIN_FILENO) == -1)
		error();
	if (dup2(pie->file, STDOUT_FILENO) == -1)
		error();
	close(pie->file);
	close_pipe(pie);
	pie->cmd = find_cmd(av[num + 2]);
	find_path(pie->cmd[0], pie);
	if (execve(pie->cmd_path, pie->cmd, NULL) == -1)
		error();
}

void	process_ing(char **av, t_pipe *pie, int num)
{
	if (dup2(pie->fd[num - 1][0], STDIN_FILENO) == -1)
		error();
	if (dup2(pie->fd[num][1], STDOUT_FILENO) == -1)
		error();
	close_pipe(pie);
	pie->cmd = find_cmd(av[num + 2]);
	find_path(pie->cmd[0], pie);
	if (execve(pie->cmd_path, pie->cmd, NULL) == -1)
		error();
}

int	pipex(t_pipe *pie, char **av, int ac, int child_process)
{
	pid_t	pid;

	while (child_process <= ac - 4)
	{
		pid = fork();
		if (pid != 0)
		{
			child_process++;
		}
		if (pid == 0)
		{
			if (child_process == 0)
				process_in(av, pie, child_process);
			if (child_process == (ac - 4))
				process_out(av, pie, child_process);
			else
				process_ing(av, pie, child_process);
		}
	}
	return (child_process);
}

int	main(int ac, char *av[], char *env[])
{
	t_pipe	*pie;
	int		child_process;

	if (ac < 5)
		print_error();
	pie = malloc(sizeof(t_pipe));
	if (!pie)
		print_error();
	get_path(pie, env);
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) != 0)
	{
		make_pipe(pie, ac - 4);
		check_file(av[1], av[ac - 1]);
		child_process = pipex(pie, av, ac, 0);
		wait_child(child_process, pie);
	}
	else
	{
		make_pipe(pie, 1);
		check_heredoc_file(".heredoc_tmp", av[ac - 1]);
		heredoc_process(pie, av, ac);
		unlink(".heredoc_tmp");
	}
	exit (0);
}

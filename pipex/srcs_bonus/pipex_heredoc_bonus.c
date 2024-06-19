/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:05:46 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/16 11:43:31 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/pipex_bonus.h"
#include "../gnl/get_next_line.h"

void	process_heredoc_in(char **av, t_pipe *pie, int num)
{
	pie->file = open(".heredoc_tmp", O_RDONLY);
	if (dup2(pie->file, STDIN_FILENO) == -1)
		error();
	if (dup2(pie->fd[0][1], STDOUT_FILENO) == -1)
		error();
	close(pie->file);
	close_pipe(pie);
	pie->cmd = find_cmd(av[num]);
	find_path(pie->cmd[0], pie);
	if (execve(pie->cmd_path, pie->cmd, NULL) == -1)
		error();
}

void	process_heredoc_out(char **av, t_pipe *pie, int num)
{
	pie->file = open(av[num + 1], O_RDWR | O_CREAT | O_APPEND, 0666);
	if (dup2(pie->fd[0][0], STDIN_FILENO) == -1)
		error();
	if (dup2(pie->file, STDOUT_FILENO) == -1)
		error();
	close(pie->file);
	close_pipe(pie);
	pie->cmd = find_cmd(av[num]);
	find_path(pie->cmd[0], pie);
	if (execve(pie->cmd_path, pie->cmd, NULL) == -1)
		error();
}

void	pipex_heredoc(t_pipe *pie, char **av, int ac, int child_process)
{
	pid_t	pid;

	pid = fork();
	if (pid != 0)
	{
		if (child_process != ac - 2)
		{
			child_process++;
			pipex_heredoc(pie, av, ac, child_process);
		}
	}
	if (pid == 0)
	{
		if (child_process == 3)
			process_heredoc_in(av, pie, child_process);
		else if (child_process == ac - 2)
			process_heredoc_out(av, pie, child_process);
	}
	close_pipe(pie);
	while (waitpid(-1, NULL, WNOHANG) != -1)
	{
	}
}

void	check_heredoc_file(char *one, char *two)
{
	if (open(one, O_RDWR | O_CREAT | O_APPEND, 0666) == -1)
		error();
	if (open(two, O_RDWR | O_CREAT | O_APPEND, 0666) == -1)
		error();
}

void	heredoc_process(t_pipe *pie, char **av, int ac)
{
	char	*str;

	pie->file = open(".heredoc_tmp", O_RDWR | O_CREAT | O_APPEND, 0666);
	while (1)
	{
		write(1, "heredoc> ", 9);
		str = get_next_line(0);
		if (!str)
			break ;
		if ((ft_strncmp(av[2], str, ft_strlen(av[2])) == 0)
			&& (ft_strlen(av[2]) == (ft_strlen(str) - 1)))
			break ;
		write(pie->file, str, ft_strlen(str));
		free(str);
	}
	free(str);
	close(pie->file);
	pipex_heredoc(pie, av, ac, 3);
}

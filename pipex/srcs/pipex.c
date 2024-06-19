/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:35:20 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/15 15:16:31 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/pipex.h"

void	find_path(char *cmd, t_pipe *pie)
{
	int	i;

	if (access(cmd, X_OK) == 0)
	{
		pie->cmd_path = ft_strdup(cmd);
		return ;
	}
	i = -1;
	while (pie->path[++i])
	{
		pie->cmd_path = ft_strjoin(pie->path[i], "/");
		pie->cmd_path = ft_strjoin(pie->cmd_path, cmd);
		if (access(pie->cmd_path, X_OK) == 0)
			return ;
		else
			free(pie->cmd_path);
	}
	if (!pie->path[i])
		error();
}

void	process_one(char **av, t_pipe *pie)
{
	pie->file = open(av[1], O_RDONLY);
	if (pie->file == -1)
		error();
	if (dup2(pie->file, STDIN_FILENO) == -1)
		error();
	if (dup2(pie->fd[1], STDOUT_FILENO) == -1)
		error();
	close(pie->file);
	close_pipe(pie->fd);
	pie->cmd = find_cmd(av[2]);
	find_path(pie->cmd[0], pie);
	if (execve(pie->cmd_path, pie->cmd, NULL) == -1)
		error();
}

void	process_two(char **av, t_pipe *pie)
{
	pie->file = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (pie->file == -1)
		error();
	if (dup2(pie->fd[0], STDIN_FILENO) == -1)
		error();
	if (dup2(pie->file, STDOUT_FILENO) == -1)
		error();
	close(pie->file);
	close_pipe(pie->fd);
	pie->cmd = ft_split(av[3], ' ');
	find_path(pie->cmd[0], pie);
	if (execve(pie->cmd_path, pie->cmd, NULL) == -1)
		error();
}

void	pipex(t_pipe *pie, char **av)
{
	int		child_process;
	pid_t	pid;

	child_process = 0;
	pid = fork();
	if (pid != 0)
	{
		child_process++;
		pid = fork();
	}
	if (pid == 0)
	{
		if (child_process == 0)
			process_one(av, pie);
		else
			process_two(av, pie);
	}
	close_pipe(pie->fd);
	while (waitpid(-1, NULL, WNOHANG) != -1)
	{
	}
}

int	main(int ac, char *av[], char *env[])
{
	t_pipe	*pie;

	if (ac != 5)
		print_error();
	check_file(av[1], av[4]);
	pie = malloc(sizeof(t_pipe));
	if (!pie)
		print_error();
	get_path(pie, env);
	if (pipe(pie->fd) == -1)
		print_error();
	pipex(pie, av);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:04:08 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/16 12:02:53 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/pipex_bonus.h"

int	print_error(void)
{
	write(1, "error:retry\n", 12);
	exit(1);
}

int	error(void)
{
	perror("zsh");
	exit (1);
}

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

void	check_file(char *one, char *two)
{
	if (open(one, O_RDONLY) == -1)
		error();
	if (open(two, O_RDWR | O_CREAT | O_TRUNC, 0666) == -1)
		error();
}

void	get_path(t_pipe *pie, char **env)
{
	char	*path;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) != 0)
			*env += 1;
		else
			break ;
	}
	path = ft_strdup(*env + 5);
	pie->path = ft_split(path, ':');
	free(path);
}

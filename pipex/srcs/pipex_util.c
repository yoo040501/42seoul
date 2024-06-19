/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:47:55 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/16 12:00:36 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/pipex.h"

int	print_error(void)
{
	write(2, "error:retry\n", 12);
	exit(1);
}

int	error(void)
{
	perror("pipex");
	exit (1);
}

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
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

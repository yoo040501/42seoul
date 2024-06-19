/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:59:45 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/15 11:01:07 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipe
{
	char	**cmd;
	char	*cmd_path;
	char	**path;
	int		fd[2];
	int		file;
}t_pipe;

int		print_error(void);
int		error(void);
void	close_pipe(int *fd);
void	get_path(t_pipe *pie, char **env);
void	check_file(char *one, char *two);

char	**find_cmd(char *av);

#endif

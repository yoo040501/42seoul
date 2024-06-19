/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:06:31 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/13 13:18:17 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipe
{
	char	**cmd;
	char	*cmd_path;
	char	**path;
	int		**fd;
	int		file;
}t_pipe;

void	process_out(char **av, t_pipe *pie, int num);
void	process_ing(char **av, t_pipe *pie, int num);
void	process_in(char **av, t_pipe *pie, int num);

int		print_error(void);
int		error(void);
void	find_path(char *cmd, t_pipe *pie);
void	get_path(t_pipe *pie, char **env);
void	check_file(char *one, char *two);

void	make_pipe(t_pipe *pie, int cnt);
void	close_pipe(t_pipe *pie);
void	wait_child(int child_process, t_pipe *pie);

void	check_heredoc_file(char *one, char *two);
void	heredoc_process(t_pipe *pie, char **av, int ac);
void	pipex_heredoc(t_pipe *pie, char **av, int ac, int child_process);
void	process_heredoc_out(char **av, t_pipe *pie, int num);
void	process_heredoc_in(char **av, t_pipe *pie, int num);

char	**find_cmd(char *av);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwook <dongwook@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:56:28 by dongwook          #+#    #+#             */
/*   Updated: 2024/06/01 18:29:34 by dongwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	make_lower(char *str);

static int	is_builtin2(char *cmd)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup(cmd);
	make_lower(str);
	if (!str)
		return (-1);
	if (ft_strlen(str) == ft_strlen("echo") \
	&& ft_strncmp(str, "echo", ft_strlen(str)) == 0)
		i = 7;
	if (ft_strlen(str) == ft_strlen("cd") \
	&& ft_strncmp(str, "cd", ft_strlen(str)) == 0)
		i = 6;
	if (ft_strlen(str) == ft_strlen("pwd") \
	&& ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		i = 5;
	if (ft_strlen(str) == ft_strlen("env") \
	&& ft_strncmp(str, "env", ft_strlen(str)) == 0)
		i = 2;
	ft_free((void **)&str);
	return (i);
}

int	is_builtin(t_node *node)
{
	if (ft_strlen(node->cmd[0]) <= 0)
		return (0);
	if (ft_strlen(node->cmd[0]) == ft_strlen("exit") \
	&& ft_strncmp(node->cmd[0], "exit", ft_strlen(node->cmd[0])) == 0)
		return (1);
	if (ft_strlen(node->cmd[0]) == ft_strlen("export") \
	&& ft_strncmp(node->cmd[0], "export", ft_strlen(node->cmd[0])) == 0)
		return (4);
	if (ft_strlen(node->cmd[0]) == ft_strlen("unset") \
	&& ft_strncmp(node->cmd[0], "unset", ft_strlen(node->cmd[0])) == 0)
		return (3);
	else
		return (is_builtin2(node->cmd[0]));
	return (0);
}

int	exec_builtin(t_env **env, t_node *node, pid_t pid)
{
	int	builtin;

	g_signal_error = 0;
	builtin = is_builtin(node);
	if (builtin == 0)
		return (0);
	if (builtin == 7)
		ft_echo(node);
	if (builtin == 6)
		ft_cd(env, node);
	if (builtin == 5)
		ft_pwd();
	if (builtin == 4)
		ft_export(env, node);
	if (builtin == 3)
		ft_unset(env, node);
	if (builtin == 2)
		ft_env(*env, node);
	if (builtin == 1)
		ft_exit(*env, node, pid);
	return (1);
}

static void	make_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

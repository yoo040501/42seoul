/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:54:37 by dongeunk          #+#    #+#             */
/*   Updated: 2024/03/15 11:00:38 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/pipex.h"

void	change_cmd(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == 39 || cmd[i] == 34)
			cmd[i] = ' ';
	}
}

void	cut_space(char **str)
{
	int		i;

	i = -1;
	while (str[0][++i])
	{
		if (str[0][i] == ' ')
		{
			str[0][i] = '\0';
			break ;
		}
	}
}

char	**find_cmd(char *av)
{
	char	**str;
	int		i;

	i = -1;
	if (ft_strncmp(av, "sed", 3) == 0)
	{
		str = ft_split(av, 39);
		cut_space(str);
	}
	else if (ft_strncmp(av, "tr", 2) == 0)
	{
		str = ft_split(av, 39);
		cut_space(str);
		free(str[2]);
		str[2] = ft_strdup(str[3]);
		str[3] = 0;
	}
	else
		str = ft_split(av, ' ');
	return (str);
}

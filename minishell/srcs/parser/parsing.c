/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwook <dongwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:26:10 by dongeunk          #+#    #+#             */
/*   Updated: 2024/05/12 02:42:23 by dongwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*save_in(char *av, t_util *util)
{
	char	*str;

	util->end = util->idx - 1;
	util->flag = util->idx;
	str = ft_strldup(av, util->start, util->end);
	str = ft_strtrim(str, " \t");
	if (!str)
		return (NULL);
	util->start = util->end + 2;
	return (str);
}

int	split_flag_save(char *av, char **str, t_util *u, char flag)
{
	while (av[++u->idx])
	{
		if (av[u->idx] == flag)
		{
			str[++u->i] = save_in(av, u);
			if (!str[u->i])
			{
				free_str(str);
				return (1);
			}
		}
		else
			u->idx = find_other(av, u->idx);
	}
	return (0);
}

char	**split_flag(char *av, int len, char flag)
{
	char	**str;
	t_util	u;

	util_init(&u);
	str = (char **)malloc(sizeof(char *) * (len + 2));
	if (!str)
		return (NULL);
	if (split_flag_save(av, str, &u, flag))
		return (NULL);
	if (u.flag == 0)
		str[++u.i] = save_in(av, &u);
	else
		str[++u.i] = save_in(av, &u);
	if (!str[u.i])
	{
		free_str(str);
		return (NULL);
	}
	str[++u.i] = NULL;
	return (str);
}

char	**parsing(char *av)
{
	int		len;
	char	*tmp;
	char	**str_pipe;

	tmp = ft_strdup(av);
	tmp = ft_strtrim(tmp, " \t");
	if (!tmp)
		return (NULL);
	if (tmp[0] == '|')
	{
		ft_free((void **)&tmp);
		g_signal_error = -2;
		return (NULL);
	}
	len = find_flag(av, '|');
	if (len == -1)
		return (NULL);
	str_pipe = split_flag(av, len, '|');
	ft_free((void **)&tmp);
	if (!str_pipe || check_line(str_pipe))
		return (NULL);
	return (str_pipe);
}

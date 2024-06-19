/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:46:20 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/11 17:55:11 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_get_str_len(int size, char **str);
int		ft_get_sep_len(char *sep);
void	ft_add_str(char *word, char **strs, char *sep, int size);
int		ft_add_sep(char *sep, char *word, int len_word);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*word;
	int		len;

	if (size < 1)
	{
		word = (char *)malloc(sizeof(char));
		*word = 0;
	}
	else
	{
		len = ft_get_str_len(size, strs);
		len += ft_get_sep_len(sep) * (size - 1);
		word = (char *)malloc(sizeof(char) * (len + 1));
		ft_add_str(word, strs, sep, size);
	}
	return (word);
}

void	ft_add_str(char *word, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	len_word;

	i = 0;
	len_word = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			word[len_word] = strs[i][j];
			j++;
			len_word++;
		}
		if (i < size - 1)
			len_word = ft_add_sep(sep, word, len_word);
		i++;
	}
	word[len_word] = '\0';
}

int	ft_get_str_len(int size, char **str)
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	ret = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
			j++;
		ret += j;
		i++;
	}
	return (ret);
}

int	ft_get_sep_len(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

int	ft_add_sep(char *sep, char *word, int len_word)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		word[len_word] = sep[i];
		i++;
		len_word++;
	}
	return (len_word);
}

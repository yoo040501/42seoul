/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:47:08 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/12 11:40:32 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
int		ft_count(char *str, char *sep);
int		ft_find_sep(char s, char *sep);
void	ft_write_word(char *str, char *sep, char **arr);
void	ft_word(char *str, char *arr, int i, int j);

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*str;
	char	*sep;
	char	**A;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	str = argv[1];
	sep = argv[2];
	A = ft_split(str,sep);
	while (A[i] != 0)
		printf("%s\n",A[i++]);
	return (0);
}
*/
char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		cnt;

	cnt = ft_count(str, charset);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!arr)
		return (0);
	ft_write_word(str, charset, arr);
	arr[cnt] = 0;
	return (arr);
}

int	ft_count(char *str, char *sep)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (!ft_find_sep(str[i], sep) && ft_find_sep(str[i + 1], sep))
			cnt++;
		i++;
	}
	return (cnt);
}

void	ft_write_word(char *str, char *sep, char **arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (ft_find_sep(str[i], sep))
			i++;
		else
		{
			j = 0;
			while (ft_find_sep(str[i + j], sep) == 0)
				j++;
			arr[k] = (char *)malloc(sizeof(char) * (j + 1));
			ft_word(str, arr[k], i, j);
			i += j;
			k++;
		}
	}
}

void	ft_word(char *str, char *arr, int i, int j)
{
	int	len;

	len = 0;
	while (j > 0)
	{
		arr[len] = str[i + len];
		len++;
		j--;
	}
	arr[len] = 0;
}

int	ft_find_sep(char s, char *sep)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (sep[i])
	{
		if (sep[i] == s)
			return (1);
		i++;
	}
	return (0);
}

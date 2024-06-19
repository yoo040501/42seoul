/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:31:02 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/07 11:12:36 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_write(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	while (i < argc)
	{
		len = ft_len(argv[i]);
		write(1, argv[i], len);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(s1 + i) < *(s2 + i))
			return (-1);
		else if (*(s1 + i) > *(s2 + i))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		first;
	int		second;
	char	*temp;

	first = 1;
	while (first < argc - 1)
	{
		second = first + 1;
		while (second < argc)
		{
			if (ft_strcmp(argv[first], argv[second]) > 0)
			{
				temp = argv[first];
				argv[first] = argv[second];
				argv[second] = temp;
			}
			second++;
		}
		first++;
	}
	ft_write(argc, argv);
	return (0);
}

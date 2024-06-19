/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:28:22 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/06 20:29:49 by dongeunk         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	len;

	while (argc > 1)
	{
		len = ft_len(argv[argc - 1]);
		write(1, argv[argc - 1], len);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}

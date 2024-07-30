/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:46:35 by dongeunk          #+#    #+#             */
/*   Updated: 2024/07/24 12:46:36 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_int(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (FAIL);
	}
	return (SUCCESS);
}

static int	check_av(int ac, char **av)
{
	int	i;

	if (ac > 6 || ac < 5)
		return (FAIL);
	else
	{
		i = 0;
		while (av[++i])
		{
			if (is_int(av[i]))
				return (FAIL);
		}
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (check_av(ac, av))
		return (error_message("error: wrong input"));
	memset(&info, 0, sizeof(t_info));
	if (info_init(ac, av, &info))
		return (error_message("error: wrong number"));
	if (philo_init(&philo, &info))
		return (error_message("error: init fail"));
	if (philo_start(philo))
		return (error_message("error: philo fail"));
	free_philo(philo);
	return (EXIT_SUCCESS);
}

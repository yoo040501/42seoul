/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:46:32 by dongeunk          #+#    #+#             */
/*   Updated: 2024/07/25 11:17:11 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	mutex_init(t_info *info)
{
	int	idx;

	if (pthread_mutex_init(&(info->print), NULL))
		return (FAIL);
	if (pthread_mutex_init(&(info->eat_check), NULL))
		return (FAIL);
	if (pthread_mutex_init(&(info->die_check), NULL))
		return (FAIL);
	if (pthread_mutex_init(&(info->eat_count), NULL))
		return (FAIL);
	info->fork = malloc(sizeof(t_fork) * info->philo_num);
	if (!(info->fork))
		return (FAIL);
	idx = -1;
	while (++idx < info->philo_num)
	{
		info->fork[idx].status = 0;
		if (pthread_mutex_init(&(info->fork[idx].lock), NULL))
			return (FAIL);
	}
	return (SUCCESS);
}

int	info_init(int ac, char **av, t_info *info)
{
	info->philo_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->die = 0;
	if (ac == 6)
	{
		info->must_eat_num = ft_atoi(av[5]);
		if (info->must_eat_num <= 0)
			return (FAIL);
	}
	if (info->philo_num <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (FAIL);
	if (mutex_init(info))
		return (FAIL);
	return (SUCCESS);
}

int	philo_init(t_philo **philo, t_info *info)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!philo)
	{
		free(info->fork);
		info->fork = NULL;
		return (FAIL);
	}
	while (++i < info->philo_num)
	{
		(*philo)[i].num = i + 1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].last_eat = 0;
		(*philo)[i].l_fork = i;
		(*philo)[i].r_fork = (i + 1) % info->philo_num;
		(*philo)[i].info = info;
	}
	return (SUCCESS);
}

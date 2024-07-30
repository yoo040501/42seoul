/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:46:23 by dongeunk          #+#    #+#             */
/*   Updated: 2024/07/25 15:55:43 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (long long)(time.tv_sec * 1000) + (long long)(time.tv_usec / 1000);
	return (ms);
}

void	check_time(long long time)
{
	long long	start_time;
	long long	now;

	start_time = get_time();
	while (1)
	{
		now = get_time();
		if ((now - start_time) >= time)
			break ;
		usleep(1000);
	}
}

void	check_die(t_philo *philo)
{
	int	i;
	int	flag;

	flag = 1;
	while (flag == 1)
	{
		i = -1;
		while (++i < philo->info->philo_num)
		{
			pthread_mutex_lock(&philo->info->eat_check);
			if ((get_time() - philo[i].last_eat) >= philo->info->time_to_die)
			{
				ft_printf(philo, "died", philo[i].num);
				philo->info->die = 1;
			}
			pthread_mutex_unlock(&philo->info->eat_check);
			pthread_mutex_lock(&(philo->info->eat_count));
			pthread_mutex_lock(&philo->info->die_check);
			if (philo->info->must_eat_num != 0
				&& philo[i].eat_count > philo->info->must_eat_num)
				philo->info->die = 1;
			pthread_mutex_unlock(&(philo->info->eat_count));
			pthread_mutex_unlock(&philo->info->die_check);
			if (philo->info->die)
			{
				flag = 0;
				break ;
			}
			usleep(10);
		}
	}
}

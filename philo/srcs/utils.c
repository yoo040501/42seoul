/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:46:40 by dongeunk          #+#    #+#             */
/*   Updated: 2024/07/25 12:01:21 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	only_one(t_philo *philo)
{
	printf("0 1 has taken a fork\n");
	usleep(philo->info->time_to_die);
	printf("%d 1 died\n", philo->info->time_to_die);
	return (SUCCESS);
}

void	free_philo(t_philo *philo)
{
	t_info	*info;
	int		i;

	i = -1;
	info = philo->info;
	while (++i < info->philo_num)
		pthread_mutex_destroy(&(info->fork[i].lock));
	pthread_mutex_destroy(&(info->print));
	pthread_mutex_destroy(&(info->die_check));
	pthread_mutex_destroy(&(info->eat_check));
	pthread_mutex_destroy(&(info->eat_count));
	free(info->fork);
	info->fork = NULL;
	free(philo);
	philo = NULL;
}

int	error_message(const char *message)
{
	printf("%s\n", message);
	return (EXIT_FAILURE);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	num = 0;
	i = -1;
	while (str[++i])
	{
		num *= 10;
		num += str[i] - '0';
	}
	return (num);
}

void	ft_printf(t_philo *philo, char *str, int num)
{
	pthread_mutex_lock(&(philo->info->print));
	pthread_mutex_lock(&(philo->info->die_check));
	if (!(philo->info->die))
	{
		printf("%lld ", get_time() - philo->info->start_time);
		printf("%d %s\n", num, str);
	}
	pthread_mutex_unlock(&(philo->info->die_check));
	pthread_mutex_unlock(&(philo->info->print));
}

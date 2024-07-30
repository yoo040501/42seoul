/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:46:28 by dongeunk          #+#    #+#             */
/*   Updated: 2024/07/25 12:06:05 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_check);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->info->eat_check);
	ft_printf(philo, "is eating", philo->num);
	check_time(philo->info->time_to_eat);
	pthread_mutex_lock(&philo->info->eat_count);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->info->eat_count);
	pthread_mutex_lock(&philo->info->fork[philo->r_fork].lock);
	philo->info->fork[philo->r_fork].status = 0;
	pthread_mutex_unlock(&philo->info->fork[philo->r_fork].lock);
	pthread_mutex_lock(&philo->info->fork[philo->l_fork].lock);
	philo->info->fork[philo->l_fork].status = 0;
	pthread_mutex_unlock(&philo->info->fork[philo->l_fork].lock);
}

static int	philo_get_fork(t_philo *philo, int dir)
{
	while (1)
	{
		pthread_mutex_lock(&philo->info->fork[dir].lock);
		if (philo->info->fork[dir].status == 0)
		{
			philo->info->fork[dir].status = 1;
			pthread_mutex_unlock(&philo->info->fork[dir].lock);
			ft_printf(philo, "has taken a fork", philo->num);
			return (SUCCESS);
		}
		pthread_mutex_unlock(&philo->info->fork[dir].lock);
		usleep(100);
	}
	return (FAIL);
}

static void	philo_get_forks(t_philo *philo)
{
	if (philo->info->time_to_sleep != philo->info->time_to_eat)
	{
		philo_get_fork(philo, philo->r_fork);
		philo_get_fork(philo, philo->l_fork);
	}
	else if (philo->num % 2 == 1)
	{
		philo_get_fork(philo, philo->l_fork);
		philo_get_fork(philo, philo->r_fork);
	}
	else
	{
		philo_get_fork(philo, philo->r_fork);
		philo_get_fork(philo, philo->l_fork);
	}
	// int	flag;

	// flag = 0;
	// while (!(philo->info->die))
	// {
	// 	pthread_mutex_lock(&philo->info->fork[philo->l_fork].lock);
	// 	pthread_mutex_lock(&philo->info->fork[philo->r_fork].lock);
	// 	if (philo->info->fork[philo->r_fork].status == 0
	// 		&& philo->info->fork[philo->l_fork].status == 0)
	// 	{
	// 		philo->info->fork[philo->r_fork].status = 1;
	// 		philo->info->fork[philo->l_fork].status = 1;
	// 		ft_printf(philo, "has taken a fork", philo->num);
	// 		ft_printf(philo, "has taken a fork", philo->num);
	// 		flag = 1;
	// 	}
	// 	pthread_mutex_unlock(&philo->info->fork[philo->l_fork].lock);
	// 	pthread_mutex_unlock(&philo->info->fork[philo->r_fork].lock);
	// 	if (flag)
	// 		break ;
	// 	usleep(100);
	// }
	philo_eat(philo);
}

int check_di(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->die_check));
	if (philo->info->die == 1)
	{
		pthread_mutex_unlock(&(philo->info->die_check));
		return (FAIL) ;
	}
	pthread_mutex_unlock(&(philo->info->die_check));
	return (SUCCESS);
}
void	*ft_p(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->num % 2)
		usleep(philo->info->time_to_eat / 2 * 1000);
	while (1)
	{
		if (check_di(philo))
			break ;
		philo_get_forks(philo);
		ft_printf(philo, "is sleeping", philo->num);
		check_time(philo->info->time_to_sleep);
		usleep(200);
		ft_printf(philo, "is thinking", philo->num);
	}
	return (0);
}

int	philo_start(t_philo *philo)
{
	int		i;
	t_info	*info;

	i = 0;
	info = philo->info;
	if (info->philo_num == 1)
		return (only_one(philo));
	philo->info->start_time = get_time();
	while (i < info->philo_num)
	{	
		philo[i].last_eat = get_time();
		if (pthread_create(&(philo[i].thread), NULL, ft_p, (void *)&philo[i]))
			return (FAIL);
		usleep(10);
		i++;
	}
	check_die(philo);
	i = -1;
	while (++i < info->philo_num)
		pthread_join(philo[i].thread, NULL);
	return (SUCCESS);
}

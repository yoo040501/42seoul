/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:46 by dongeunk          #+#    #+#             */
/*   Updated: 2024/06/19 14:52:35 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define TURE	0
# define FALSE	1

typedef struct s_info
{
	int				philo_num;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				must_eat_num;
	int				*fork;
	pthread_mutex_t	mutex_start;
	pthread_mutex_t	mutex_print;
}	t_info;

typedef struct s_philo
{
	pthread_t	thread;
	int			last_eat;
	int			num;
	int			l_fork;
	int			r_fork;
	t_info		*info;
}	t_philo;

#endif
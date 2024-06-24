/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:46 by dongeunk          #+#    #+#             */
/*   Updated: 2024/06/21 19:21:49 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define SUCCESS	0
# define FAIL		1

typedef struct s_info
{
	int				philo_num;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				eat_num;
	int				*fork;
	int				die;
	int				eat_check;
	long long			start_time;
	//int				monitor;// 종료 flag
	//pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_monitor;
	pthread_mutex_t	mutex_eat_cnt;
	pthread_mutex_t	mutex_last_eat;
}	t_info;

typedef struct s_philo
{
	pthread_t	thread;
	int			last_eat;
	int			num;
	int			l_fork;
	int			r_fork;
	int			eat_count;
	//long		check_time;// 쓰레드의 시작시간
	t_info		*info;
}	t_philo;

int	error_message(const char message);
int	philo_init(t_philo **philo, t_info *info);
int	info_init(int ac, char **av, t_info *info);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:46 by dongeunk          #+#    #+#             */
/*   Updated: 2024/07/25 12:05:34 by dongeunk         ###   ########.fr       */
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
# define USING		1
# define AVAILABLE	0

typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				status;
}	t_fork;

typedef struct s_info
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	long long		start_time;
	int				die;
	t_fork			*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	die_check;
	pthread_mutex_t	eat_check;
	pthread_mutex_t	eat_count;
}	t_info;

typedef struct s_philo
{
	pthread_t	thread;
	int			num;
	int			l_fork;
	int			r_fork;
	int			eat_count;
	long long	last_eat;
	t_info		*info;
}	t_philo;

int			philo_init(t_philo **philo, t_info *info);
int			info_init(int ac, char **av, t_info *info);

int			error_message(const char *message);
int			ft_atoi(char *str);
void		ft_printf(t_philo *philo, char *str, int num);
void		free_philo(t_philo *philo);
int			only_one(t_philo *philo);

int			philo_start(t_philo *philo);
void		*ft_p(void *p);
long long	get_time(void);

void		check_die(t_philo *philo);
void		check_time(long long time);

#endif

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

	int				philo_num; // 철학자 수
	int				life_time; // 철학자 생명 시간
	int				eat_time; // 식사 소요 시간
	int				sleep_time; // 수면 소요 시간
	int				eat_num; // 식사 횟수
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_monitor;
	pthread_mutex_t	mutex_eat_cnt;
	pthread_mutex_t	mutex_last_eat;
	int				monitor; // 종료 flag
}	t_info;

typedef struct s_philo
{
	pthread_t	thread;
	int			last_eat;
	int			num;
	int			l_fork;
	int			r_fork;
	t_info		*info;

	int			id; // 철학자 넘버
	int			eat_count; // 철학자 식사 횟수
	int			left; // 왼쪽 포크 넘버
	int			right; // 오른쪽 포크 넘버
	long		last_eat; // 마지막 식사 시간
	long		last_time; // 쓰레드의 시작시간 (작명센스 ㅈㅅ)
	pthread_t	thread; // 쓰레드 ID
	t_arg		*info; // 입력 인자 값
}	t_philo;

#endif

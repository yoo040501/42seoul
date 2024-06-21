#include "../include/philo.h"

int	info_init(int ac, char **av, t_info *info)
{
	info->philo_num = ft_atoi(av[1]);
	info->to_die = ft_atoi(av[2]);
	info->to_eat = ft_atoi(av[3]);
	info->to_sleep = ft_atoi(av[4]);
	info->monitor = 0;
	info->fork = malloc(sizeof(int) * (info->philo_num));
	if (!(info->fork))
		return (FAIL);
	memset(info->fork, 0, info->philo_num);
	if (ac == 6)
	{
		info->eat_num = ft_atoi(av[5]);
		if (info->eat_num <= 0)
			return (FAIL);
	}
	else
		info->eat_num = 0;
	return (SUCCESS);
}

int	philo_init(t_philo **philo, t_info *info)
{
	int		i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!philo)
	{
		free(info->fork);
		info->fork = NULL;
		return (FAIL);
	}
	memset(*philo, 0, info->philo_num);
	while (i < info->philo_num)
	{
		(*philo)[i].num = i + 1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].last_eat = 0;
		//(*philo)[i].last_time = 0;
		(*philo)[i].l_fork = i;
		(*philo)[i].r_fork = (i + 1) % info->philo_num;
		(*philo)[i].info = info;
		i++;
	}
	return (SUCCESS);
}

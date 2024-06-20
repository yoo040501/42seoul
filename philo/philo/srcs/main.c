#include "../include/philo.h"

int	is_int(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (FALSE);
	}
	return (TURE);
}

int	check_av(int ac, char **av)
{
	int	flag;
	int	i;

	flag = 0;
	if (ac > 6 || ac < 5)
		flag = 1;
	else
	{
		i = 0;
		while (av[++i])
		{
			if (is_int(av[i]))
			{
				flag = 1;
				break ;
			}
		}
	}
	return (flag);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (check_av(ac, av))
		return (error_message(""));
	if (info_init(ac, av, info))
		return (error_message(""));
	
	return (EXIT_SUCCESS);
}

int	init_argv(t_arg *arg, int argc, char **argv)
{
	arg->philo_num = ft_atoi(argv[1]);
	arg->life_time = ft_atoi(argv[2]);
	arg->eat_time = ft_atoi(argv[3]);
	arg->sleep_time = ft_atoi(argv[4]);
	arg->monitor = 0;
	if (arg->philo_num <= 0 || arg->life_time < 0 || \
		arg->eat_time < 0 || arg->sleep_time < 0)
		return (1);
	if (argc == 6)
	{
		arg->eat_num = ft_atoi(argv[5]);
		if (arg->eat_num <= 0)
			return (1);
	}
	else
		arg->eat_num = 0;
	return (0);
}

int	init_philo(t_philo **philo, t_arg *arg)
{
	int		i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * arg->philo_num);
	if (!philo)
		return (1);
	while (i < arg->philo_num)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % arg->philo_num;
		(*philo)[i].last_eat = 0;
		(*philo)[i].last_time = 0;
		(*philo)[i].arg = arg;
		i++;
	}
	return (0);
}

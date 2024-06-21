#include "../include/philo.h"

int	is_int(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (FAIL);
	}
	return (SUCCESS);
}

int	check_av(int ac, char **av)
{
	int	i;

	if (ac > 6 || ac < 5)
		return (FAIL);
	else
	{
		i = 0;
		while (av[++i])
		{
			if (is_int(av[i]))
				return (FAIL);
		}
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (check_av(ac, av))
		return (error_message("un number"));
	if (info_init(ac, av, &info))
		return (error_message(""));
	if (philo_init(&philo, &info))
		return (error_message(""));
	return (EXIT_SUCCESS);
}


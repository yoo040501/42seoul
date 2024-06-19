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
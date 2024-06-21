#include "../include/philo.h"

int	error_message(const char message)
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
		num = str[i] - '0';
	}
	return (num);
}

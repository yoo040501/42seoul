#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i=1;i<ac;i++)
		{
			int j=-1;
			while (av[i][++j])
			{
				std::cout << static_cast<char>(toupper(av[i][j]));
			}
		}
		std::cout << std::endl;
	}
	return (0);
}

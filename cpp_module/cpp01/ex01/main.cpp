#include "Zombie.hpp"

int	main(void)
{
	Zombie* test;

	test = zombieHorde(5, "test");

	for (int i=0;i<5;i++)
		test[i].annouce();
	delete[] test;
	return (0);
}

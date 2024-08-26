#include "Zombie.hpp"

// void aa(void)
// {
// 	system("leaks ex01");
// }

int	main(void)
{
	Zombie* test;

	test = zombieHorde(5, "test");

	for (int i=0;i<5;i++)
		test[i].annouce();
	//atexit(aa);
	delete[] test;
	return (0);
}

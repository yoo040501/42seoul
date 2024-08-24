#include "Zombie.hpp"

int	main(void)
{
	Zombie *one = newZombie("one");

	one->annouce();
	
	randomChump("two");
	delete one;
	return (0);
}

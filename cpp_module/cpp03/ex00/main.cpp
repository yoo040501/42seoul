#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	one("one");
	ClapTrap	two("two");

	one.beRepaired(10);
	for (int i=0;i<9;i++)
	{
		one.attack("two");
		if (one.getEnergyPoints() > 0)
			two.takeDamage(one.getAttackDamage());
	}
	one.beRepaired(5);
	return 0;
}

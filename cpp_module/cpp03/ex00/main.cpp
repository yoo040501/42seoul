#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	one("one");
	ClapTrap	two("two");

	for (int i=0;i<11;i++)
	{
		one.attack("two");
		if (one.getEnergyPoints() > 0)
			two.takeDamage(one.getAttackDamage());
	}
	return 0;
}

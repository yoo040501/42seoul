#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "-----------TESTING CLAPTRAP-------------\n" << std::endl;
	{
		ClapTrap	one;
		ClapTrap	two("two");

		one.beRepaired(10);
		for (int i=0;i<10;i++)
		{
			one.attack("two");
			if (one.getEnergyPoints() >= 0)
				two.takeDamage(one.getAttackDamage());
		}
		two.takeDamage(100);
		one.beRepaired(5);
	}
	std::cout << "\n-------------------TESTING SCAVTRAP------------------\n" << std::endl;
	{
		ScavTrap a;
		ScavTrap b("b");

		b.attack("Trap");
		for (int i = 0; i < 50; i++)
			a.attack("Trap");
		a.beRepaired(22);
		a.takeDamage(21);
		a.beRepaired(22);
		a.guardGate();
		a.guardGate();
		b.attack("a");
		b.takeDamage(100);
		b.takeDamage(15);
		b.attack("a");
	}
}

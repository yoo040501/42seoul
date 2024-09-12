#include "FragTrap.hpp"

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
		two.takeDamage(10);
		one.beRepaired(5);
	}

	std::cout << "\n\n-------------TESTING FRAGTRAP---------------------\n" << std::endl;
	{
		FragTrap a;
		FragTrap b("bbbb");

		a.highFivesGuys();
		a.attack("Trap");
		a.takeDamage(101);
		a.beRepaired(12);
		a.attack("Trap");
		b.highFivesGuys();
		// for(int i = 0; i < 101; i++)
		// 	b.attack("Someone");
	}
}

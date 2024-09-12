#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
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
	}

	std::cout << "\n\n-----------------TESTING DIAMONDTRAP------------------\n" << std::endl;
	{
		DiamondTrap a;
		DiamondTrap b("b");
		DiamondTrap c(a);

		a.whoAmI();
		a.attack("Someone");
		b.whoAmI();
		b.attack("Someone");
		c.whoAmI();
	}
}

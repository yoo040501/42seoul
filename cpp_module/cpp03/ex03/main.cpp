#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	DiamondTrap A("A");
	DiamondTrap B("B");
	DiamondTrap C;

	C = B;
	std::cout << A.getAttackDamage() << std::endl;
	for (int i=0;i<6;i++)
	{
		A.attack("B");
		B.takeDamage(A.getAttackDamage());
	}
	C.attack("A");
	B.attack("A");

	std::cout << "\n\n-=-----------------TESTING DIAMONDTRAP------------------\n" << std::endl;
	{
		DiamondTrap a;
		DiamondTrap b("G");
		DiamondTrap c(a);

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		c.whoAmI();
	}
}

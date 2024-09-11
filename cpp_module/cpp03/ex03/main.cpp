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
}

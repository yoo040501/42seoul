#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap A("A");
	ScavTrap B("B");
	ScavTrap C = B;

	//C = B;
	std::cout << A.getAttackDamage() << std::endl;
	for (int i=0;i<6;i++)
	{
		A.attack("B");
		B.takeDamage(A.getAttackDamage());
	}
	C.attack("A");
	B.attack("A");
}

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap A("A");
	FragTrap B("B");
	FragTrap C = B;

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

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

	std::cout << "\n\n-------------TESTING FRAGTRAP---------------------\n" << std::endl;
	{
		FragTrap e;
		FragTrap f("Chadd");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		e.highFiveGuys();
		e.attack("some random dude");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("some random dude");
		f.highFiveGuys();
		// for(int i = 0; i < 101; i++)
		// 	f.attack("FragTrap-clone");
	}
}

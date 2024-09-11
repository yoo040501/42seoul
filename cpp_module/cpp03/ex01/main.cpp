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

	std::cout << "-----------TESTING CLAPTRAP-----------------\n" << std::endl;
	{
		ClapTrap a;
		ClapTrap b("b");

		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
	}
	std::cout << "\n-------------------TESTING SCAVTRAP------------------\n" << std::endl;
	{
		ScavTrap c;
		ScavTrap d("d");

		c.attack("CloneTrap");
		// for (int i = 0; i < 50; i++)
		// 	c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone");
	}
}

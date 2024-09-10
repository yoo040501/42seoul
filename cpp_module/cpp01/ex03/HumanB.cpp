#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "HunmanB Constructor called" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB Destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void){
	std::cout << this->name << " attacks with their " << this->weapon->getType() << '\n';
}

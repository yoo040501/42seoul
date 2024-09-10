#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << "HumanA Constructor called" << std::endl;
}

HumanA::~HumanA(void){
	std::cout << "HumanA Destructor called" << std::endl;
}

void	HumanA::attack(void){
	std::cout << this->name << " attacks with their " << this->weapon.getType() << '\n';
}

#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << name << "Zombie Constructor called" << std::endl;
	name = "Zombie";
}

Zombie::~Zombie(){
	std::cout << name << "Zombie Destructor called" << std::endl;
}

void Zombie::annouce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name){
	this->name = name;
}

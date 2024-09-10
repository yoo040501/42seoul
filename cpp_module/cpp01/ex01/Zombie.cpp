#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Zombie Constructor called" << std::endl;
	name = "Zombie";	
}

Zombie::~Zombie(){
	std::cout << "Zombie Destructor called" << std::endl;
}

void Zombie::annouce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name){
	this->name = name;
}

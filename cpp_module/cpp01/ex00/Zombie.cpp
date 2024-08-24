#include "Zombie.hpp"

Zombie::Zombie(){
	name = "";	
}

Zombie::~Zombie(){
}

void Zombie::annouce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name){
	this->name = name;
}

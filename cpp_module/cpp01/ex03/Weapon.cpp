#include "Weapon.hpp"

Weapon::Weapon(){
	std::cout << "Weapon Constrcutor called" << std::endl;
}

Weapon::Weapon(std::string type) : type(type){
	std::cout << type << " Weapon Constrcutor called" << std::endl;
}

Weapon::~Weapon(){
	std::cout << type << " Weapon Destructor called" << std::endl;
}

void Weapon::setType(std::string type){
	this->type = type;
}

const std::string&	Weapon::getType(void) const{
	return (this->type);
}

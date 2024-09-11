#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << COLOR_RED << "Animal Default Constructor called" << COLOR_NONE << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &Animal){
	std::cout << COLOR_RED << "Animal Copy constructor called" << COLOR_NONE << std::endl;
	this->type = Animal.type;
}

Animal& Animal::operator=(const Animal &A){
	std::cout << COLOR_RED << "Animal Copy assignment operator called" << COLOR_NONE << std::endl;
	if (this != &A)
		this->type = A.type;
	return (*this);
}

Animal::~Animal(void){
	std::cout << COLOR_RED << "Animal Destructor called" << COLOR_NONE << std::endl;
}

std::string	Animal::getType(void) const{
	return this->type;
}

void	Animal::makeSound(void) const{}

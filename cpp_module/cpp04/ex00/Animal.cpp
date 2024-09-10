#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &Animal){
	this->type = Animal.getType();
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &A){
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &A)
		this->type = A.getType();
	return (*this);
}

Animal::~Animal(void){
	std::cout << "Animal Destructor called" << std::endl;
}

std::string	Animal::getType(void) const{
	return this->type;
}

void	Animal::makeSound(void) const{}

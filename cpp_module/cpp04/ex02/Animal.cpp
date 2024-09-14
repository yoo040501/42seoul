#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << COLOR_RED << "Animal Default Constructor called" << COLOR_NONE << std::endl;
}

Animal::Animal(const Animal &Animal){
	this->type = Animal.getType();
	std::cout << COLOR_RED << "Animal Copy constructor called" << COLOR_NONE << std::endl;
}

Animal& Animal::operator=(const Animal &A){
	if (this != &A)
		this->type = A.getType();
	std::cout << COLOR_RED << "Animal Copy assignment operator called" << COLOR_NONE << std::endl;
	return (*this);
}

Animal::~Animal(void){
	std::cout << COLOR_RED << "Animal Destructor called" << COLOR_NONE << std::endl;
}

const std::string&	Animal::getType(void) const{
	return this->type;
}

Brain*	Animal::getBrain(void) const{
	return NULL;
}

void	Animal::makeSound(void) const{}

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << COLOR_PURPLE << "Dog Default Constructor called" << COLOR_NONE << std::endl;
}

Dog::Dog(const Dog &Dog){
	this->type = Dog.type;
	std::cout << COLOR_PURPLE << "Dog Copy constructor called" << COLOR_NONE << std::endl;
}

Dog& Dog::operator=(const Dog &D){
	std::cout << COLOR_PURPLE << "Dog Copy assignment operator called" << COLOR_NONE << std::endl;
	if (this != &D)
		this->type = D.type;
	return (*this);
}

Dog::~Dog(void){
	std::cout << COLOR_PURPLE << "Dog Destructor called" << COLOR_NONE << std::endl;
}

std::string	Dog::getType(void) const{
	return this->type;
}

void	Dog::makeSound(void) const{
	std::cout << "Bowwow! Bowwow!" << std::endl;
}

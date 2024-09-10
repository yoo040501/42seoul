#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &Dog){
	this->type = Dog.getType();
	std::cout << "Dog Copy constructor called\n";
}

Dog& Dog::operator=(const Dog &D){
	std::cout << "Dog Copy assignment operator called\n";
	if (this != &D)
		this->type = D.getType();
	return (*this);
}

Dog::~Dog(void){
	std::cout << "Dog Destructor called\n";
}

std::string	Dog::getType(void) const{
	return this->type;
}

void	Dog::makeSound(void) const{
	std::cout << "Bowwow! Bowwow!" << std::endl;
}

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "	Dog Default Constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog &Dog){
	std::cout << "	Dog Copy constructor called" << std::endl;
	this->type = Dog.getType();
	this->brain = new Brain;
}

Dog& Dog::operator=(const Dog &D){
	std::cout << "	Dog Copy assignment operator called" << std::endl;
	if (this != &D){
		this->type = D.getType();
		this->brain = new Brain;
		}
	return (*this);
}

Dog::~Dog(void){
	std::cout << "	Dog Destructor called" << std::endl;
	delete	brain;
}

std::string	Dog::getType(void) const{
	return this->type;
}

void	Dog::makeSound(void) const{
	std::cout << "Bowwow! Bowwow!" << std::endl;
}

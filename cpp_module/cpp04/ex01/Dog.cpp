#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << COLOR_PURPLE << "Dog Default Constructor called" << COLOR_NONE << std::endl;
	this->type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog &Dog){
	std::cout << COLOR_PURPLE << "Dog Copy constructor called" << COLOR_NONE << std::endl;
	this->type = Dog.getType();
	this->brain = new Brain;
}

Dog& Dog::operator=(const Dog &D){
	std::cout << COLOR_PURPLE << "Dog Copy assignment operator called" << COLOR_NONE << std::endl;
	if (this != &D){
		delete brain;
		this->type = D.getType();
		this->brain = new Brain;
		}
	return (*this);
}

Dog::~Dog(void){
	std::cout << COLOR_PURPLE << "Dog Destructor called" << COLOR_NONE << std::endl;
	delete	brain;
}

std::string	Dog::getType(void) const{
	return this->type;
}

void	Dog::makeSound(void) const{
	std::cout << "Bowwow! Bowwow!" << std::endl;
}

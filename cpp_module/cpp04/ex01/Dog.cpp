#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << COLOR_PURPLE << "Dog Default Constructor called" << COLOR_NONE << std::endl;
	this->type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog &Dog){
	this->type = Dog.getType();
	this->brain = new Brain(*Dog.brain);
	std::cout << COLOR_PURPLE << "Dog Copy constructor called" << COLOR_NONE << std::endl;
}

Dog& Dog::operator=(const Dog &D){
	if (this != &D){
		delete brain;
		Animal::operator=(D);
		this->type = D.getType();
		this->brain = new Brain(*D.brain);
		}
	std::cout << COLOR_PURPLE << "Dog Copy assignment operator called" << COLOR_NONE << std::endl;
	return (*this);
}

Dog::~Dog(void){
	std::cout << COLOR_PURPLE << "Dog Destructor called" << COLOR_NONE << std::endl;
	delete	brain;
}

Brain*	Dog::getBrain(void) const{
	return this->brain;
}
void	Dog::makeSound(void) const{
	std::cout << "Bowwow! Bowwow!" << std::endl;
}

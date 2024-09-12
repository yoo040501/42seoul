#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << COLOR_PURPLE << "Dog Default Constructor called" << COLOR_NONE << std::endl;
}

Dog::Dog(const Dog &Dog): Animal(Dog){
	this->type = Dog.type;
	std::cout << COLOR_PURPLE << "Dog Copy constructor called" << COLOR_NONE << std::endl;
}

Dog& Dog::operator=(const Dog &D){
	if (this != &D){
		Animal::operator=(D);
		this->type = D.type;
		}
	std::cout << COLOR_PURPLE << "Dog Copy assignment operator called" << COLOR_NONE << std::endl;
	return (*this);
}

Dog::~Dog(void){
	std::cout << COLOR_PURPLE << "Dog Destructor called" << COLOR_NONE << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "Bowwow! Bowwow!" << std::endl;
}

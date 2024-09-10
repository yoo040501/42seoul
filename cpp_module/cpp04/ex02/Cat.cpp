#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "	Cat Default Constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat &Cat){
	std::cout << "	Cat Copy constructor called" << std::endl;
	this->type = Cat.getType();
	this->brain = new Brain;
}

Cat& Cat::operator=(const Cat &C){
	std::cout << "	Cat Copy assignment operator called" << std::endl;
	if (this != &C){
		this->type = C.getType();
		this->brain = new Brain;
	}
	return (*this);
}

Cat::~Cat(void){
	std::cout << "	Cat Destructor called" << std::endl;
	delete	brain;
}

std::string	Cat::getType(void) const{
	return this->type;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow~! Meow~!" << std::endl;
}

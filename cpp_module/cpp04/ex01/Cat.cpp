#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << COLOR_BLUE << "Cat Default Constructor called" << COLOR_NONE << std::endl;
	this->type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat &Cat){
	std::cout << COLOR_BLUE << "Cat Copy constructor called" << COLOR_NONE << std::endl;
	this->type = Cat.getType();
	this->brain = new Brain;
}

Cat& Cat::operator=(const Cat &C){
	std::cout << COLOR_BLUE << "Cat Copy assignment operator called" << COLOR_NONE << std::endl;
	if (this != &C){
		this->type = C.getType();
		this->brain = new Brain;
	}
	return (*this);
}

Cat::~Cat(void){
	std::cout << COLOR_BLUE << "Cat Destructor called" << COLOR_NONE << std::endl;
	delete	brain;
}

std::string	Cat::getType(void) const{
	return this->type;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow~! Meow~!" << std::endl;
}

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << COLOR_BLUE << "Cat Default Constructor called" << COLOR_NONE << std::endl;
}

Cat::Cat(const Cat &Cat){
	this->type = Cat.type;
	std::cout << COLOR_BLUE << "Cat Copy constructor called" << COLOR_NONE << std::endl;
}

Cat& Cat::operator=(const Cat &C){
	std::cout << COLOR_BLUE << "Cat Copy assignment operator called" << COLOR_NONE << std::endl;
	if (this != &C)
		this->type = C.type;
	return (*this);
}

Cat::~Cat(void){
	std::cout << COLOR_BLUE << "Cat Destructor called" << COLOR_NONE << std::endl;
}

std::string	Cat::getType(void) const{
	return this->type;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow~! Meow~!" << std::endl;
}

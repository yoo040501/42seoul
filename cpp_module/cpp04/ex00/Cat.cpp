#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &Cat){
	this->type = Cat.getType();
	std::cout << "Cat Copy constructor called\n";
}

Cat& Cat::operator=(const Cat &C){
	std::cout << "Cat Copy assignment operator called\n";
	if (this != &C)
		this->type = C.getType();
	return (*this);
}

Cat::~Cat(void){
	std::cout << "Cat Destructor called\n";
}

std::string	Cat::getType(void) const{
	return this->type;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow~! Meow~!" << std::endl;
}

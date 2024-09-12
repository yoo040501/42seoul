#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << COLOR_RED << "WrongAnimal Default Constructor called" << COLOR_NONE << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal){
	std::cout << COLOR_RED << "WrongAnimal Copy constructor called" << COLOR_NONE << std::endl;
	this->type = WrongAnimal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &A){
	std::cout << COLOR_RED << "WrongAnimal Copy assignment operator called" << COLOR_NONE << std::endl;
	if (this != &A)
		this->type = A.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void){
	std::cout << COLOR_RED << "WrongAnimal Destructor called" << COLOR_NONE << std::endl;
}

const std::string&	WrongAnimal::getType(void) const{
	return this->type;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << COLOR_BROWN << "This is WrongAnimal" << std::endl;
}

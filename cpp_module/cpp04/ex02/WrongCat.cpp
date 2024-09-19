#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << COLOR_BLUE << "WrongCat Default Constructor called" << COLOR_NONE << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat){
	this->type = WrongCat.type;
	std::cout << COLOR_BLUE << "WrongCat Copy constructor called" << COLOR_NONE << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &C){
	std::cout << COLOR_BLUE << "WrongCat Copy assignment operator called" << COLOR_NONE << std::endl;
	if (this != &C)
		this->type = C.type;
	return (*this);
}

WrongCat::~WrongCat(void){
	std::cout << COLOR_BLUE << "WrongCat Destructor called" << COLOR_NONE << std::endl;
}

const std::string&	WrongCat::getType(void) const{
	return this->type;
}

void	WrongCat::makeSound(void) const{
	std::cout << "Woem~! Woem~!" << std::endl;
}

Brain*	WrongCat::getBrain(void) const{
	return (this->brain);
}

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	brain = new Brain;
	std::cout << COLOR_BLUE << "Cat Default Constructor called" << COLOR_NONE << std::endl;
}

Cat::Cat(const Cat &Cat) : Animal(Cat){
	this->type = Cat.type;
	this->brain = new Brain;
	std::cout << COLOR_BLUE << "Cat Copy constructor called" << COLOR_NONE << std::endl;
}

Cat& Cat::operator=(const Cat &C){
	if (this != &C){
		Animal::operator=(C);
		this->type = C.type;
		this->brain = new Brain;
	}
	std::cout << COLOR_BLUE << "Cat Copy assignment operator called" << COLOR_NONE << std::endl;
	return (*this);
}

Cat::~Cat(void){
	delete	brain;
	std::cout << COLOR_BLUE << "Cat Destructor called" << COLOR_NONE << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow~! Meow~!" << std::endl;
}

Brain*	Cat::getBrain(void) const{
	return (this->brain);
}

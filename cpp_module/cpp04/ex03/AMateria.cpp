#include "AMateria.hpp"

AMateria::AMateria(void){
	std::cout << COLOR_BLACK << "AMateria Default Constructor called" << COLOR_NONE << std::endl;
}

AMateria::AMateria(std::string const& type): _type(type){
	std::cout << COLOR_BLACK << "AMateria Constructor called" << COLOR_NONE << std::endl;
}


AMateria::AMateria(const AMateria& other){
	this->_type = other._type;
	std::cout << COLOR_BLACK << "AMateria Copy Constructor called" << COLOR_NONE << std::endl;
}

AMateria& AMateria::operator=(const AMateria &A){
	if (this != &A)
	{
		this->_type = A._type;
	}
	std::cout << COLOR_BLACK << "AMateria Copy assignment Constructor called" << COLOR_NONE << std::endl;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << COLOR_BLACK << "AMateria Destructor called" << COLOR_NONE << std::endl;
}

std::string const& AMateria::getType() const{
	return this->_type;
}

void AMateria::use(ICharacter& target){
		std::cout << COLOR_BLACK << "none" << target.getName() << COLOR_NONE << std::endl;
}

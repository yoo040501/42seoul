#include "AMateria.hpp"

AMateria::AMateria(void){
	std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type): _type(type){
	std::cout << "AMateria Constructor called" << std::endl;
}


AMateria::AMateria(const AMateria& other){
	this->_type = other._type;
	std::cout << "AMateria Copy Constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &A){
	if (this != &A)
	{
		this->_type = A._type;
	}
	std::cout << "AMateria Copy assignment Constructor called" << std::endl;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const& AMateria::getType() const{
	return this->_type;
}

void AMateria::use(ICharacter& target){
		std::cout << "none" << target.getName() << std::endl;
}

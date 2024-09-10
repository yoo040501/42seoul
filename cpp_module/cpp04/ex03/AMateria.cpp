#include "AMateria.hpp"

AMateria::AMateria(std::string const& type): type(type){
	std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destuctor called" << std::endl;
}

std::string const& AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter& target){
	std::cout << "none" << std::endl;
}
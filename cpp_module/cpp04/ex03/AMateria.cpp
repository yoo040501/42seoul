#include "AMateria.hpp"

AMateria::AMateria(std::string const& type): type(type){
	std::cout << "AMateria Constructor called" << std::endl;
}


AMateria::AMateria(const AMateria& other){
	std::cout << "AMateria Copy Constructor called" << std::endl;
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria &A){
	std::cout << "AMateria Copy assignment Constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const& AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter& target){
	std::cout << "none" << std::endl;
}
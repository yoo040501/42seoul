#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource(){
	std::cout << "MateriaSource Create" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other): IMateriaSource(other){
	std::cout<< "MateriaSource Copy Create" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *){

}

AMateria*	MateriaSource::createMateria(std::string const& type){

}
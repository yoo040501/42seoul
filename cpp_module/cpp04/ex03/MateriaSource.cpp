#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource(){
	std::cout << "MateriaSource Create" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other): IMateriaSource(other){
	std::cout<< "MateriaSource Copy Create" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *){
		for (int i = 0; i < 4; i++)
	{
		if (materia && this->_learnInventory[i] == NULL)
		{
			if (this->inLearnInventory(materia))
				this->_learnInventory[i] = materia;
			else
				this->_learnInventory[i] = materia;
			std::cout << "Materia " << this->_learnInventory[i]->getType() << " learned at index " << i << std::endl;
			return ;
		}
	}
	if (materia)
		std::cout << "Cannot learn materia, inventory for MateriaSource is full!" << std::endl;
	else
		std::cout << "Cannot learn invalid materia" << std::endl;
	if (!this->inLearnInventory(materia))
		delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const& type){
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] && this->_learnInventory[i]->getType() == type)
			return (this->_learnInventory[i]->clone());
	}
	std::cout << "Cannot create materia, " << type << " is invalid!" << std::endl;
	return (0);
}

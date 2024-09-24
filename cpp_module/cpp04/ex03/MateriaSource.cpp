#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(){
	std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other): IMateriaSource(other){
	for (int i=0;i<4;i++)
			_learnInventory[i] = other._learnInventory[i]->clone();
	std::cout<< "MateriaSource Copy Called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& oth){
	if (this != &oth){
		for (int i=0;i<4;i++)
			_learnInventory[i] = oth._learnInventory[i]->clone();
	}
	std::cout << "MateriaSource Copy assignment Called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(){
	for (int i=0;i<4;i++){
		if (_learnInventory[i])
			delete _learnInventory[i];
	}
	std::cout << "MateriaSource Destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m){
	for (int i = 0; i < 4; i++)
	{
		if (m && this->_learnInventory[i] == NULL)
		{
			this->_learnInventory[i] = m;
			std::cout << "Materia " << this->_learnInventory[i]->getType() << " learned at index " << i << std::endl;
			return ;
		}
	}
	if (m){
		std::cout << "Cannot learn materia, inventory for MateriaSource is full!" << std::endl;
		delete m;
	}
	else
		std::cout << "Cannot learn invalid Materia" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type){
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] && this->_learnInventory[i]->getType() == type)
			return (this->_learnInventory[i]->clone());
	}
	std::cout << "!!Materia 생성 불가 " << type << " 타입 유효하지 않음!!" << std::endl;
	return (0);
}

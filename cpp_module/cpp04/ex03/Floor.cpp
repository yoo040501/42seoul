#include "Floor.hpp"

AMateria* Floor::_remove[4] = {NULL, NULL, NULL, NULL};

Floor::Floor(void){
	for (int i=0;i<4;i++)
		_remove[i] = NULL;
	std::cout << COLOR_BLACK << "Floor default constructor called" << COLOR_NONE << std::endl;
}

Floor::Floor(const Floor &oth){
	for (int i=0;i<4;i++)
		_remove[i] = oth._remove[i]->clone();
	std::cout << COLOR_BLACK << "Floor Copy constructor called" << COLOR_NONE << std::endl;
}

Floor&	Floor::operator=(const Floor &F){
	if (this != &F)
	{
		for (int i=0;i<4;i++){
			if (_remove[i])
				delete	_remove[i];
			if (F._remove[i])
				_remove[i] = F._remove[i]->clone();
		}
	}
	return (*this);
}

Floor::~Floor(){
	for (int i=0;i<4;i++)
	{
		if (_remove[i])
			delete _remove[i];
	}
	std::cout << COLOR_BLACK << "Floor Destructor called" << COLOR_NONE << std::endl;
}

void	Floor::unequip_memory(AMateria* a){
	for (int i=0;i<4;i++){
		if (_remove[i] == NULL){
			_remove[i] = a;
			return ;
		}
	}
	delete _remove[0];
	_remove[0] = a;
}

AMateria*	Floor::get_inven(int idx){
	return _remove[idx];
}

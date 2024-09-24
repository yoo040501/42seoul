#include "Character.hpp"

Character::Character(std::string const& name) : _name(name)
{
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << COLOR_BROWN << "Character " << this->_name << " 생성" << COLOR_NONE << std::endl;
}

Character::Character(Character const& src) : _name(src._name)
{
	for (int i = 0; i < 4; i++){
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
	std::cout << COLOR_BROWN << "Character " << this->_name << " 복사 완료" << COLOR_NONE << std::endl;
}

Character& Character::operator=(Character const& C)
{
	if (this != &C)
	{
		this->_name = C._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (C._inventory[i])
				this->_inventory[i] = C._inventory[i]->clone();		
		}
	}
	std::cout << COLOR_BROWN << "Character " << this->_name << " 복사 대입 연산 완료" << COLOR_NONE << std::endl;
    return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << COLOR_BROWN << "Character " << this->_name << " 삭제" << COLOR_NONE << std::endl;
}

void	Character::unequip(int idx){
	if (this->_inventory[idx] == NULL)
	{
		std::cout << COLOR_BROWN << "Character" << this->_name << "don't have Materia" << COLOR_NONE << std::endl;
		return ;
	}
	Floor::unequip_memory(this->_inventory[idx]);
	this->_inventory[idx] = NULL;
	std::cout << COLOR_BROWN << "Character " << this->_name << " unequipped" << COLOR_NONE << std::endl;
}

void	Character::use(int idx, ICharacter& target){
	if (this->_inventory[idx] != NULL){
		this->_inventory[idx]->use(target);
		return ;
	}
	std::cout << COLOR_BROWN << "can't use" << COLOR_NONE << std::endl;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++){
		if (m && this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << COLOR_BROWN << "Character " << this->_name << " equipped with " << m->getType() << COLOR_NONE << std::endl;
			return;
		}
	}
    std::cout << COLOR_BROWN << "Character " << this->_name << " can't equip " << COLOR_NONE << std::endl;
}

std::string const& Character::getName() const {
    return this->_name;
}


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
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = src._inventory[i];
	std::cout << COLOR_BROWN << "Character " << this->_name << " 복사 완료" << COLOR_NONE << std::endl;
}

Character& Character::operator=(Character const& C)
{
	if (this != &C)
	{
		this->_name = C._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = C._inventory[i];
	}
	std::cout << COLOR_BROWN << "Character " << this->_name << " 복사 대입 연산 완료" << COLOR_NONE << std::endl;
    return *this;
}

Character::~Character()
{
	std::cout << COLOR_BROWN << "Character " << this->_name << " 삭제" << COLOR_NONE << std::endl;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

void	Character::unequip(int idx){
	if (this->_inventory[idx] == NULL)
	{
		std::cout << COLOR_BROWN << "Character" << this->_name << "don't have Materia" << COLOR_NONE << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
	std::cout << COLOR_BROWN << "Character " << this->_name << " unequipped with " << COLOR_NONE << std::endl;
}

void	Character::use(int idx, ICharacter& target){
	if (this->_inventory[idx] != NULL){
		this->_inventory[idx]->use(target);
		return ;
	}
	std::cout << COLOR_BROWN << "nononononononono" << COLOR_NONE << std::endl;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << COLOR_BROWN << "Character " << this->_name << " equipped with " << m->getType() << COLOR_NONE << std::endl;
			return;
		}
	}
    std::cout << COLOR_BROWN << "Character " << this->_name << " can't equip " << m->getType() << COLOR_NONE << std::endl;
}

std::string const& Character::getName() const {
    return this->_name;
}

// use(int, ICharacter&) 멤버 함수는 AMateria::use 함수를 호출하고, 
// 대상 파라미터를 전달해야 합니다. 복사 생성자나 복사 할당 연산자를 사용할 때는 깊은 복사가 이루어져야 하며, 
// Character가 소멸될 때는 Materia들이 삭제되어야 합니다.

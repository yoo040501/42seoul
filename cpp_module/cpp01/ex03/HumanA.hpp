#pragma once
#include "Weapon.hpp"

class HumanA{
	std::string	name;
	Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack(void);
};

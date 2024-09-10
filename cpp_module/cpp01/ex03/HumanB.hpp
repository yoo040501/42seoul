#pragma once

#include "Weapon.hpp"

class HumanB{
	private:
		Weapon *weapon;
		std::string name;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &weapon);
		void	attack(void);
};

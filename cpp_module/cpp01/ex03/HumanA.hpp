#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA{
	Weapon		weapon;
	std::string	name;
	public:
		HumanA();
		~HumanA();
		void setWeapon(Weapon weapon);
		void attack(void);
};
#endif
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{
	std::string type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		void		setType(std::string type);
		std::string	getType(void);
};
#endif
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		void		setType(std::string type);
		std::string	getType(void) const;
};

#endif

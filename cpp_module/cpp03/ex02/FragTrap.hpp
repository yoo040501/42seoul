#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& FragTrap);
		FragTrap& operator=(const FragTrap &F);
		~FragTrap(void);
		
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);
		void	highFivesGuys(void);
};

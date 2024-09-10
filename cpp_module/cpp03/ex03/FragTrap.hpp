#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& FragTrap);
		FragTrap& operator=(const FragTrap &F);
		~FragTrap(void);
		
		virtual void	attack(const std::string& target);
		virtual void 	beRepaired(unsigned int amount);
		virtual void	takeDamage(unsigned int amount);
		void	highFivesGuys(void);
};

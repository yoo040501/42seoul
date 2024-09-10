#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& ScavTrap);
		ScavTrap& operator=(const ScavTrap &S);
		~ScavTrap(void);
		
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);
		void	guardGate(void);
};

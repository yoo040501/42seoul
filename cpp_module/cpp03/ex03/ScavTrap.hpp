#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& ScavTrap);
		ScavTrap& operator=(const ScavTrap &S);
		~ScavTrap(void);
		
		virtual void	attack(const std::string& target);
		virtual void	beRepaired(unsigned int amount);
		virtual void	takeDamage(unsigned int amount);
		void	guardGate(void);
};

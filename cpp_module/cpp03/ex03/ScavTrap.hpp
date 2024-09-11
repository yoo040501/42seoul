#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& ScavTrap);
		ScavTrap& operator=(const ScavTrap &S);
		virtual ~ScavTrap(void);
		
		void	attack(const std::string& target);
		void	guardGate(void);
};

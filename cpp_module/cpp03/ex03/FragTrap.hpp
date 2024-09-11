#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& FragTrap);
		FragTrap& operator=(const FragTrap &F);
		virtual~FragTrap(void);
		
		void	highFivesGuys(void);
};

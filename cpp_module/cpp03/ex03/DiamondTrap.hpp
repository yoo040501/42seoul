#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& DiamondTrap);
		DiamondTrap& operator=(const DiamondTrap& D);
		~DiamondTrap();

		void	whoAmI(void);
};

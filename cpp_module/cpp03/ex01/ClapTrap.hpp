#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	private:
		std::string		name;
		int	HitPoints;
		int	EnergyPoints;
		int	AttackDamage;
	
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& ClapTrap);
		ClapTrap& operator=(const ClapTrap &C);
		~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getname(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		void			setHitPoints(unsigned int point);
		void			setEnergyPoints(unsigned int point);

};

#endif

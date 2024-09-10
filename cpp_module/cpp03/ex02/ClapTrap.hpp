#pragma once

#include <iostream>

class ClapTrap{
	protected:
		std::string		name;
		int			HitPoints;
		int			EnergyPoints;
		int			AttackDamage;
	
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& ClapTrap);
		ClapTrap& operator=(const ClapTrap &C);
		virtual ~ClapTrap(void);

		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);

		std::string		getname(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		void			setHitPoints(unsigned int point);
		void			setEnergyPoints(unsigned int point);

};

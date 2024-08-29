#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	// private:
	// 	std::string		name;
	// 	int			HitPoints;
	// 	int			EnergyPoints;
	// 	int			AttackDamage;

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

		std::string		getname(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		void			setHitPoints(unsigned int point);
		void			setEnergyPoints(unsigned int point);
};

#endif
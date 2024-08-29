#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap(){}

void	ScavTrap::guardGate(void){

}

void	ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else{
		if (this->EnergyPoints == 0)
			std::cout << "Not Enough Energy" << std::endl;
		else
			std::cout << "This ScavTrap already die" << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " takeDamage " << amount << std::endl;
		if (this->HitPoints <= static_cast<int>(amount))
			this->HitPoints = 0;
		else
			this->HitPoints -= static_cast<int>(amount);
	}
	if (this->HitPoints == 0)
		std::cout << "ScavTrap " << this->name << " is died" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount){
	if (this->EnergyPoints > 0 && this->HitPoints > 0){
		std::cout << "ScavTrap " << this->name << " berepaired" << std::endl;
		this->setEnergyPoints(this->EnergyPoints - 1);
		if (this->HitPoints + static_cast<int>(amount) > 10)
			this->HitPoints = 10;
		else
			this->HitPoints += static_cast<int>(amount);
	}
	else{
	if (this->EnergyPoints == 0)
		std::cout << "ScavTrap " << this->name << " Not Enough Energy" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " already die" << std::endl;
	}
}

std::string	ScavTrap::getname(void) const{
	return (this->name);
}

unsigned int	ScavTrap::getHitPoints(void) const{
	return this->HitPoints;
}

unsigned int	ScavTrap::getAttackDamage(void) const{
	return this->AttackDamage;
}

unsigned int	ScavTrap::getEnergyPoints(void) const{
	return this->EnergyPoints;
}

void	ScavTrap::setEnergyPoints(unsigned int point){
	this->EnergyPoints = point;
}

void	ScavTrap::setHitPoints(unsigned int point)
{
	this->HitPoints = point;
}
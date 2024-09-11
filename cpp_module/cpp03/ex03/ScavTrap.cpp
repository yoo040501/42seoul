#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(){
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->name = name;
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ScavTrap) : ClapTrap(ScavTrap){
	this->name = ScavTrap.name;
	this->HitPoints = ScavTrap.HitPoints;
	this->EnergyPoints = ScavTrap.EnergyPoints;
	this->AttackDamage = ScavTrap.AttackDamage;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &S){
	if (this != &S) {
		ClapTrap::operator=(S);
		this->name = S.name;
		this->HitPoints = S.HitPoints;
		this->EnergyPoints = S.EnergyPoints;
		this->AttackDamage = S.AttackDamage;
	}
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::guardGate(void){
	std::cout << "ScavTrap " << this->name << "is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{

	if (EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else{
		if (this->EnergyPoints == 0)
			std::cout << "Not Enough Energy" << std::endl;
		else
			std::cout << "This ScavTrap "<< this->name << " already die" << std::endl;
	}
}

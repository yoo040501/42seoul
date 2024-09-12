#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(){
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "\033[0;34mScavTrap Default constructor called\033[0;0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->name = name;
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "\033[0;34mScavTrap " << this->name << " constructor called\033[0;0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ScavTrap) : ClapTrap(ScavTrap){
	this->name = ScavTrap.name;
	this->HitPoints = ScavTrap.HitPoints;
	this->EnergyPoints = ScavTrap.EnergyPoints;
	this->AttackDamage = ScavTrap.AttackDamage;
	std::cout << "\033[0;34mScavTrap Copy constructor called\033[0;0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &S){
	if (this != &S) {
		ClapTrap::operator=(S);
		this->name = S.name;
		this->HitPoints = S.HitPoints;
		this->EnergyPoints = S.EnergyPoints;
		this->AttackDamage = S.AttackDamage;
	}
	std::cout << "\033[0;34mScavTrap Copy assignment operator called\033[0;0m" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void){
	std::cout << "\033[0;34mScavTrap Destructor called\033[0;0m" << std::endl;
}

void	ScavTrap::guardGate(void){
	std::cout << "\033[0;34mScavTrap " << this->name << "is now in Gate keeper mode.\033[0;0m" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{

	if (EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "\033[0;34m" << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!\033[0;0m" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else{
		if (this->EnergyPoints == 0)
			std::cout << "\033[0;34mNot Enough Energy\033[0;0m" << std::endl;
		else
			std::cout << "\033[0;34mThis "<< this->name << " already die\033[0;0m" << std::endl;
	}
}

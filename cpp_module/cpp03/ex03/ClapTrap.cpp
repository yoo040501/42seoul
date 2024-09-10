#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): HitPoints(10), EnergyPoints(10), AttackDamage(0){
	std::cout << "ClapTrap Default constructor called" << std::endl;
	name = "";
}

ClapTrap::ClapTrap(std::string name): name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0){
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ClapTrap){
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	this->name = ClapTrap.getname();
	this->HitPoints = ClapTrap.getHitPoints();
	this->AttackDamage = ClapTrap.getAttackDamage();
	this->EnergyPoints = ClapTrap.getEnergyPoints();
}

ClapTrap& ClapTrap::operator=(const ClapTrap &C){
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &C)
	{
		this->name = C.getname();
		this->HitPoints = C.getHitPoints();
		this->AttackDamage = C.getAttackDamage();
		this->EnergyPoints = C.getEnergyPoints();
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else{
		if (this->EnergyPoints == 0)
			std::cout << "Not Enough Energy" << std::endl;
		else
			std::cout << "This ClapTrap already die" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " takeDamage " << amount << std::endl;
		if (this->HitPoints <= static_cast<int>(amount))
			this->HitPoints = 0;
		else
			this->HitPoints -= static_cast<int>(amount);
	}
	if (this->HitPoints == 0)
		std::cout << "ClapTrap " << this->name << " is died" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->EnergyPoints > 0 && this->HitPoints > 0){
		std::cout << "ClapTrap " << this->name << " berepaired" << std::endl;
		this->setEnergyPoints(this->EnergyPoints - 1);
		if (this->HitPoints + static_cast<int>(amount) > 10)
			this->HitPoints = 10;
		else
			this->HitPoints += static_cast<int>(amount);
	}
	else{
	if (this->EnergyPoints == 0)
		std::cout << "ClapTrap " << this->name << " Not Enough Energy" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " already die" << std::endl;
	}
}

std::string	ClapTrap::getname(void) const{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const{
	return this->HitPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const{
	return this->AttackDamage;
}

unsigned int	ClapTrap::getEnergyPoints(void) const{
	return this->EnergyPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int point){
	this->EnergyPoints = point;
}

void	ClapTrap::setHitPoints(unsigned int point)
{
	this->HitPoints = point;
}

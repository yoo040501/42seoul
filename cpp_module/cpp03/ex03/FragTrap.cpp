#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& FragTrap) : ClapTrap(FragTrap){
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &S){
	if (this != &S) {
		ClapTrap::operator=(S);
	}
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{

	if (EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else{
		if (this->EnergyPoints == 0)
			std::cout << "Not Enough Energy" << std::endl;
		else
			std::cout << "This FragTrap "<< this->name << " already die" << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints > 0)
	{
		std::cout << "FragTrap " << this->name << " takeDamage " << amount << std::endl;
		if (this->HitPoints <= static_cast<int>(amount))
			this->HitPoints = 0;
		else
			this->HitPoints -= static_cast<int>(amount);
	}
	if (this->HitPoints == 0)
		std::cout << "FragTrap " << this->name << " is died" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount){
	if (this->EnergyPoints > 0 && this->HitPoints > 0){
		std::cout << "FragTrap " << this->name << " berepaired" << std::endl;
		this->setEnergyPoints(this->EnergyPoints - 1);
		if (this->HitPoints + static_cast<int>(amount) > 10)
			this->HitPoints = 10;
		else
			this->HitPoints += static_cast<int>(amount);
	}
	else{
	if (this->EnergyPoints == 0)
		std::cout << "FragTrap " << this->name << " Not Enough Energy" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " already die" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->name << " wants a highfive!"<< std::endl;
}
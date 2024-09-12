#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){
	std::cout << "FragTrap Default constructor called" << std::endl;
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& FragTrap) : ClapTrap(FragTrap){
	std::cout << "FragTrap Copy constructor called" << std::endl;
	this->name = FragTrap.name;
	this->HitPoints = FragTrap.HitPoints;
	this->EnergyPoints = FragTrap.EnergyPoints;
	this->AttackDamage = FragTrap.AttackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap &F){
	if (this != &F) {
		ClapTrap::operator=(F);
		this->name = F.name;
		this->HitPoints = F.HitPoints;
		this->EnergyPoints = F.EnergyPoints;
		this->AttackDamage = F.AttackDamage;
	}
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->name << " wants a highfive!"<< std::endl;
}

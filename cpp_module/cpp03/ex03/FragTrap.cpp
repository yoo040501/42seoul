#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){
	std::cout << "\033[0;33mFragTrap Default constructor called\033[0;0m" << std::endl;
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "\033[0;33mFragTrap " << this->name << " constructor called\033[0;0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& FragTrap) : ClapTrap(FragTrap){
	this->name = FragTrap.name;
	this->HitPoints = FragTrap.HitPoints;
	this->EnergyPoints = FragTrap.EnergyPoints;
	this->AttackDamage = FragTrap.AttackDamage;
	std::cout << "\033[0;33mFragTrap Copy constructor called\033[0;0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &F){
	if (this != &F) {
		ClapTrap::operator=(F);
		this->name = F.name;
		this->HitPoints = F.HitPoints;
		this->EnergyPoints = F.EnergyPoints;
		this->AttackDamage = F.AttackDamage;
	}
	std::cout << "\033[0;33mFragTrap Copy assignment operator called\033[0;0m" << std::endl;
	return *this;
}

FragTrap::~FragTrap(void){
	std::cout << "\033[0;33mFragTrap Destructor called\033[0;0m" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "\033[0;33mFragTrap " << this->name << " wants a highfive!\033[0;0m"<< std::endl;
}

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(){
	this->name = "UNKNOWN";
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name){
	this->name = name;
	this->EnergyPoints = FragTrap::EnergyPoints;
	this->HitPoints = ScavTrap::HitPoints;
	this->AttackDamage = FragTrap::AttackDamage;
	std::cout << "DiamondTrap " << this->name << " constructor called"<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& DiamondTrap): ClapTrap(DiamondTrap), FragTrap(DiamondTrap), ScavTrap(DiamondTrap){
	this->name = DiamondTrap.name;
	this->HitPoints = DiamondTrap.HitPoints;
	this->EnergyPoints = DiamondTrap.EnergyPoints;
	this->AttackDamage = DiamondTrap.AttackDamage;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& D){
	if (this != &D)
	{
		ClapTrap::operator=(D);
		this->name = D.name;
		this->HitPoints = D.HitPoints;
		this->EnergyPoints = D.EnergyPoints;
		this->AttackDamage = D.AttackDamage;
	}
	std::cout << "Diamond Copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void){
	std::cout << "DiamondTrap name is " << name << " ClapTrap name is " << ClapTrap::name << std::endl;
}

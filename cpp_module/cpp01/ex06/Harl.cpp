#include "Harl.hpp"

Harl::Harl(void){
	std::cout << "Harl Constructor called" << std::endl;
}

Harl::~Harl(void){
	std::cout << "Harl Destructor called" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::levels	Harl::getlevel(std::string const level)
{
	std::string L[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	for (int i=0;i<4;i++)
	{
		if (level == L[i])
			return static_cast<Harl::levels>(i);
	}
	return Harl::UNKNOWN;
}

void	Harl::print(int level)
{
	for (int i=level;i<4;i++)
	{
		switch (i)
		{
			case (0):
				debug();
				break;
			case (1):
				info();
				break;
			case (2):
				warning();
				break;
			case (3):
				error();
				break;
		}
		std::cout << std::endl;
	}
}

void	Harl::complain(std::string level){

	levels Lev = getlevel(level);

	switch (Lev)
	{
		case DEBUG:
			print(DEBUG);
			break;
		
		case INFO:
			print(INFO);
			break;

		case WARNING:
			print(WARNING);
			break;

		case ERROR:
			print(ERROR);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

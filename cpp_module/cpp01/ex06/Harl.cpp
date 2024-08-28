#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
	std::cout << "I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
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
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}

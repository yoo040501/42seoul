#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable!\nI want to speak to the manager now.\n";
}

Harl::Harl(void){

}

Harl::~Harl(void){
	
}

void	Harl::complain(std::string level){
	void (Harl::*complaints[4])() = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
        };

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i=0;i<4;i++)
	{
		if (level == levels[i])
		{
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "Probably complaining about insignificant problems\n";
}

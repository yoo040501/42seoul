#pragma once

#include <iostream>

class Zombie{
	std::string name;

	public:
		Zombie();
		~Zombie();
		void annouce(void);
		void set_name(std::string name);

};
	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);

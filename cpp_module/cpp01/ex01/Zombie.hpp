#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
	std::string name;

	public:
		Zombie();
		~Zombie();
		void annouce(void);
		void set_name(std::string name);

};

Zombie*	zombieHorde(int N, std::string name);

#endif

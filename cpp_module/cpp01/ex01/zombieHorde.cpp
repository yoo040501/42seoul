#include "Zombie.hpp"
#include <string>
#include <sstream>

Zombie* zombieHorde(int N, std::string name){
	Zombie* zombie = new Zombie[N];
	std::stringstream 	ss;

	for (int i=0;i<N;i++){
		ss.str("");
		ss << i;
		zombie[i].set_name(name + ss.str());
	}

	return (zombie);
}

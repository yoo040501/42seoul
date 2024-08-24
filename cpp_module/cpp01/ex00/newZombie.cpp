#include "Zombie.hpp"


Zombie*	newZombie(std::string name){
	Zombie* zombie;
	zombie->set_name(name);

	return (zombie);
}

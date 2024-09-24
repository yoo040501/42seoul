#pragma once

#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

class Floor
{
	private:
		static AMateria*	_remove[4];
	public:
		Floor();
		Floor(const Floor &oth);
		Floor& operator=(const Floor &F);
		~Floor();

		static void	unequip_memory(AMateria* a);
		AMateria*	get_inven(int idx);
};

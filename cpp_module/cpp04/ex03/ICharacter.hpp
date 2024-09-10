#pragma once

#include <iostream>
#include "AMateria.hpp"

class	AMateria;

class ICharacter
{
	private:
		int	idx;
	public:
		ICharacter();
		virtual ~ICharacter() {}
		
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
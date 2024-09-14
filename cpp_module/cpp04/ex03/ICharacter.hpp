#pragma once

#include <iostream>
#include "Color.hpp"
#include "AMateria.hpp"

class	AMateria;

class ICharacter
{
	protected:
	
	public:
		ICharacter();
		ICharacter(const ICharacter& other);
		ICharacter	operator=(const ICharacter& oth);
		virtual ~ICharacter();
		
		virtual std::string const&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;
};
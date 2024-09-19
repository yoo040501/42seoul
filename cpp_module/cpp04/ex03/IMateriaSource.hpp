#pragma once

#include <iostream>
#include "Color.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

class	AMateria;

class IMateriaSource
{
	public:
		virtual	~IMateriaSource(){}

		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(std::string const& type) = 0;
};

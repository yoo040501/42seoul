#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class MateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const& type);
};

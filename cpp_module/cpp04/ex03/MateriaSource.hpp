#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& M);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const& type);
};

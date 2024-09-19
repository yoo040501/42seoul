#pragma once

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure &C);
		~Cure();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

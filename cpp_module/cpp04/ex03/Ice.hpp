#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		/* data */
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& I);
		~Ice();
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

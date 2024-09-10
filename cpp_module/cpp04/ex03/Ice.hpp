#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		/* data */
	public:
		Ice();
		Ice(const Ice& Ice);
		Ice& operator=(const Ice& I);
		~Ice();
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

Ice::Ice(/* args */)
{
}

Ice::~Ice()
{
}

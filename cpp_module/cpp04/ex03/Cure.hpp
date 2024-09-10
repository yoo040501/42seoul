#pragma once

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:
	
	public:
		Cure(std::string const& type);
		Cure(const Cure& Cure);
		Cure& operator=(const Cure &C);
		~Cure();
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

Cure::Cure(std::string const& type)
{

}

Cure::~Cure()
{
}

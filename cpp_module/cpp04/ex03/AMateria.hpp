#pragma once

#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(const AMateria& AMateria);
		AMateria& operator=(const AMateria &A);
		virtual	~AMateria();

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) const ;
};


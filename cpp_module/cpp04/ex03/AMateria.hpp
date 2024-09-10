#pragma once

#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class AMateria
{
	private:
		AMateria(const AMateria& AMateria);
		AMateria& operator=(const AMateria &A);
	protected:
		std::string	const type;

	public:
		AMateria(void);
		AMateria(std::string const& type);
		virtual	~AMateria();

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class	AMateria;

class IMateriaSource
{
	private:
		/* data */
	public:
		IMateriaSource(/* args */);
		~IMateriaSource();
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

IMateriaSource::IMateriaSource(/* args */)
{
}

IMateriaSource::~IMateriaSource()
{
}

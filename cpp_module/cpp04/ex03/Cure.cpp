#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "* Cure: Default constructor called *" << std::endl;
}

Cure::Cure( Cure const & other ) : AMateria("cure")
{
	this->_type = other._type;
	std::cout << "* Cure Copy constructor called *" << std::endl;
}

Cure&	Cure::operator=( const Cure& C) {
	if (this != &C)
	{
		AMateria::operator=(C);
		this->_type = C._type;
	}
	std::cout << "* Cure Copy assignment constructor called *" << std::endl;

	return *this;
}

Cure::~Cure()
{
	std::cout << "* Cure: Destructor called *" << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

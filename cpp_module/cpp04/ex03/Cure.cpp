#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << COLOR_GREEN << "* Cure: Default constructor called *" << COLOR_NONE << std::endl;
}

Cure::Cure( Cure const & other ) : AMateria("cure")
{
	this->_type = other._type;
	std::cout << COLOR_GREEN << "* Cure Copy constructor called *" << COLOR_NONE << std::endl;
}

Cure&	Cure::operator=( const Cure& C) {
	if (this != &C)
	{
		AMateria::operator=(C);
		this->_type = C._type;
	}
	std::cout << COLOR_GREEN << "* Cure Copy assignment constructor called *" << COLOR_NONE << std::endl;

	return *this;
}

Cure::~Cure()
{
	std::cout << COLOR_GREEN << "* Cure: Destructor called *" << COLOR_NONE << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter& target )
{
	std::cout << COLOR_GREEN << "* heals " << target.getName() << "'s wounds *" << COLOR_NONE << std::endl;
}

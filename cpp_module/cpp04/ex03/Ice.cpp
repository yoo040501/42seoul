#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << COLOR_BLUE << "* Ice Default constructor called *" << COLOR_NONE << std::endl;
}

Ice::Ice( Ice const & other) : AMateria("ice")
{
	this->_type = other._type;
	std::cout << COLOR_BLUE << "* Ice Copy constructor called *" << COLOR_NONE << std::endl;
}

Ice&	Ice::operator=( const Ice& I) {
	if (this != &I)
	{
		AMateria::operator=(I);
		this->_type = I._type;
	}
	std::cout << COLOR_BLUE << "* Ice Copy assignment constructor called *" << COLOR_NONE << std::endl;

	return *this;
}

Ice::~Ice()
{
	std::cout << COLOR_BLUE << "* Ice Destructor called *" << COLOR_NONE << std::endl;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use( ICharacter& target )
{
	std::cout << COLOR_BLUE << "* shoots an ice bolt at " << target.getName() << " *" << COLOR_NONE << std::endl;
}

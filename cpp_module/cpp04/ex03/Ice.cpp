#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "* Ice: Default constructor called *" << std::endl;
}

Ice::Ice( Ice const & other) : AMateria("ice")
{
    *this = other;
    std::cout << "* Ice: Copy constructor called *" << std::endl;
}

Ice&   Ice::operator=( const Ice& I) {
    if (this != &I)
    {
        this->type = I.type;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "* Ice: Destructor called *" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

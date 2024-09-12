#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << "* Cure: materia is created *" << std::endl;
}

Cure::Cure( Cure const & src ) : AMateria("Cure")
{
    *this = src;
    std::cout << "* Cure: materia is copied *" << std::endl;
}

Cure&   Cure::operator=( const Cure& C) {
    if (this != &C)
    {
        this->_type = C._type;
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "* Cure: Cure is destroyed *" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use( ICharacter& target )
{
    std::cout << "I shoots an Cure bolt at " << target.getName() << std::endl;
}

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &F){
	this->value = F.getRawBits();
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed &F){
	std::cout << "Copy assignment operator called\n";
	if (this != &F)
		this->value = F.getRawBits();
	return (*this);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

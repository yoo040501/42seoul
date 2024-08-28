#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	this->value = (num * (1 << this->bits));
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->bits));
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
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const{
	return static_cast<float>(value) / (1 << this->bits);
}

int	Fixed::toInt(void) const
{
	return value >> this->bits;
}

std::ostream& operator<<(std::ostream& o, const Fixed& F)
{
	o << F.toFloat();
	return o;
}

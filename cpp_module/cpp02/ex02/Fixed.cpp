#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (num * (1 << this->bits));
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &F){
	this->value = F.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &F){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F)
		this->value = F.getRawBits();
	return (*this);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
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

// 비교 연산자
bool	Fixed::operator<(const Fixed& F) const{
	return this->value < F.value;
}
bool	Fixed::operator>(const Fixed& F) const{
	return this->value > F.value;
}
bool	Fixed::operator<=(const Fixed& F) const{
	return this->value <= F.value;
}
bool	Fixed::operator>=(const Fixed& F) const{
	return this->value >= F.value;
}
bool	Fixed::operator==(const Fixed& F) const{
	return this->value == F.value;
}

// 산술 연산자
Fixed	Fixed::operator+(const Fixed& F) const{
	Fixed	temp(toFloat() + F.toFloat());
	return	temp;
}

Fixed	Fixed::operator-(const Fixed& F) const{
	Fixed	temp(toFloat() - F.toFloat());
	return	temp;
}

Fixed	Fixed::operator*(const Fixed& F) const{
	Fixed	temp(toFloat() * F.toFloat());
	return	temp;
}

Fixed	Fixed::operator/(const Fixed& F) const{
	Fixed	temp(toFloat() / F.toFloat());
	return	temp;
}


// 증감 연산자
Fixed	Fixed::operator++(int){
	Fixed	temp(*this);
	value++;
	return temp;
}

Fixed&	Fixed::operator++(){
	value++;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	temp(*this);
	value--;
	return temp;
}

Fixed&	Fixed::operator--(){
	value--;
	return *this;
}

// Add these four public overloaded member functions to your class
Fixed&	Fixed::max( Fixed &a, Fixed &b) {
	return (a > b ? a: b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b){
	return (a > b ? a : b);
}

Fixed&	Fixed::min( Fixed &a, Fixed &b) {
	return (a < b ? a: b);
}

const Fixed&	Fixed::min(const Fixed &a,const Fixed &b) {
	return (a < b ? a: b);
}
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <fstream>

class Fixed
{
	private:
		int					value;
		const static int	bits = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& Fixed);
		Fixed& operator=(const Fixed &F);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator<(const Fixed& F) const;
		bool	operator>(const Fixed& F) const;
		bool	operator<=(const Fixed& F) const;
		bool	operator>=(const Fixed& F) const;
		bool	operator==(const Fixed& F) const;

		Fixed	operator+(const Fixed& F) const;
		Fixed	operator-(const Fixed& F) const;
		Fixed	operator*(const Fixed& F) const;
		Fixed	operator/(const Fixed& F) const;

		Fixed	operator++(int);
		Fixed&	operator++();
		Fixed	operator--(int);
		Fixed&	operator--();

		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& o, const Fixed& F);
#endif

#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

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
};

std::ostream& operator<<(std::ostream& o, const Fixed& F);

#pragma once

#include <iostream>

class Fixed
{
	private:
		int					value;
		const static int	bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& Fixed);
		Fixed& operator=(const Fixed &F);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

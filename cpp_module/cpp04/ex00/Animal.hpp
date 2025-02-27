#pragma once

#include <iostream>
#include "Color.hpp"

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& Animal);
		Animal& operator=(const Animal &A);
		virtual	~Animal();

		virtual void		makeSound(void) const;
		const std::string&	getType(void) const;
};

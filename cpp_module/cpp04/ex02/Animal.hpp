#pragma once

#include <iostream>
#include "Brain.hpp"
#include "Color.hpp"

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& Animal);
		Animal& operator=(const Animal &A);
		virtual	~Animal();

		virtual void		makeSound(void) const = 0;
		virtual	Brain*		getBrain(void) const;
		const std::string&	getType(void) const;
};

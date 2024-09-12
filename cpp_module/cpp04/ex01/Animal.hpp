#pragma once

#include <iostream>
#include "Color.hpp"
#include "Brain.hpp"

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& Animal);
		Animal& operator=(const Animal &A);
		virtual	~Animal();

		virtual void		makeSound(void) const;
		virtual	Brain*		getBrain(void) const;
		const std::string&	getType(void) const;
};

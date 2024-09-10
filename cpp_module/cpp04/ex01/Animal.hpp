#pragma once

#include <iostream>

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& Animal);
		Animal& operator=(const Animal &A);
		virtual	~Animal();

		virtual void	makeSound(void) const;
		virtual std::string	getType(void) const;
};

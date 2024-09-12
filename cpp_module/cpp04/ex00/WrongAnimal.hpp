#pragma once

#include <iostream>
#include "Color.hpp"

class WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& WrongAnimal);
		WrongAnimal& operator=(const WrongAnimal &A);
		~WrongAnimal();

		void				makeSound(void) const;
		const std::string&	getType(void) const;
};

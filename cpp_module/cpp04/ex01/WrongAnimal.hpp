#pragma once

#include <iostream>
#include "Color.hpp"
#include "Brain.hpp"

class WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& WrongAnimal);
		WrongAnimal& operator=(const WrongAnimal &A);
		~WrongAnimal();

		void				makeSound(void) const;
		Brain*				getBrain(void) const;
		const std::string&	getType(void) const;
};

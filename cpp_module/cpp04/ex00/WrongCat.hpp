#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat& WrongCat);
		WrongCat& operator=(const WrongCat &C);
		~WrongCat();

		void				makeSound(void) const;
		const std::string&	getType(void) const;
};


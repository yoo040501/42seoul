#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	private:
		Brain*	brain;
		
	public:
		WrongCat();
		WrongCat(const WrongCat& WrongCat);
		WrongCat& operator=(const WrongCat &C);
		~WrongCat();

		void				makeSound(void) const;
		Brain*				getBrain() const;
		const std::string&	getType(void) const;
};


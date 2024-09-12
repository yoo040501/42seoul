#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain*	brain;

	public:
		Cat();
		Cat(const Cat& Cat);
		Cat& operator=(const Cat &C);
		~Cat();

		void	makeSound(void) const;
		Brain*	getBrain() const;
};

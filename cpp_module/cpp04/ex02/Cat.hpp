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
		virtual	~Cat();

		void		makeSound(void) const;
		std::string	getType(void) const;
};

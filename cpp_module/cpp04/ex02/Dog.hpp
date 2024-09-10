#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *brain;
		
	public:
		Dog();
		Dog(const Dog& Dog);
		Dog& operator=(const Dog &D);
		virtual	~Dog();

		void		makeSound(void) const;
		std::string	getType(void) const;
};

#pragma once

#include <iostream>
#include <stdexcept>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Intern(const Intern &copy);
		Intern& operator=(const Intern &I);
	public:
		Intern();
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
		class NotExistException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#pragma once

#include <iostream>
#include <stdexcept>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &I);
		~Intern();

		AForm	makeForm(std::string name, std::string target);
};

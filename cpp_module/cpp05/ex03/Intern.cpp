#include "Intern.hpp"

Intern::Intern(void){}

// Intern::Intern(const Intern &copy)
// {
// }

// Intern&	Intern::operator=(const Intern &I){}

Intern::~Intern(){}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	const std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	int Index = -1;
    for (int i = 0; i < 3; ++i) {
        if (name == forms[i]) {
            Index = i;
            break;
        }
    }

    switch (Index)
    {
		case 0:
			return RobotomyRequestForm::createForm(target);
		case 1:
			return PresidentialPardonForm::createForm(target);
		case 2:
			return ShrubberyCreationForm::createForm(target);
		default:
			throw	NotExistException();
    }
}

const char* Intern::NotExistException::what() const throw() {
	return "\033[0;31mThis form name doesn`t exist\033[0m";
}

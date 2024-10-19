#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& P);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor)const;
		std::string getTarget(void)const;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *P);

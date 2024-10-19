#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& R);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor)const;
		std::string getTarget(void)const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *R);

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& R);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

	void execute(Bureaucrat const &executor)const;
	std::string getTarget(void)const;
	~RobotomyRequestForm();
};
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

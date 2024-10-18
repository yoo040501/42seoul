#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	/* data */
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& R);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
	~RobotomyRequestForm();
};

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &R): AForm("RobotomyRequestForm", 72, 45), _target(R.getTarget())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	AForm::execute(executor);
	if (rand() % 2 == 1)
		std::cout << "\033[0;34mDRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized\033[0;0m" << std::endl;
	else
		std::cout << "\033[0;34mRobotomy failed\033[0;0m" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

AForm*	RobotomyRequestForm::createForm(std::string target){
	std::cout <<  "Intern creates RobotomyRequestForm" << std::endl;
	return (new RobotomyRequestForm(target));
}


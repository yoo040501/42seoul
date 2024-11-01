#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &R): AForm("PresidentialPardonForm", 25, 5), _target(R.getTarget())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	AForm::execute(executor);
	std::cout << "\033[0;34m" << this->_target << " has been pardoned by Zaphod Beeblebrox.\033[0;0m" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void)const
{
	return (this->_target);
}

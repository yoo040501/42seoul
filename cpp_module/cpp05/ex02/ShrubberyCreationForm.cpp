#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &S): AForm("ShrubberyCreationForm", 145, 137), _target(S.getTarget())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if (executor.getGrade() > this->getExecuteLevel())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSigned());
	else
	{
		std::string	outfile = this->_target + "_shrubbery";
		std::ofstream outf;
		outf.open(outfile);
		if (outf.fail()){
			std::cout << "Error: can`t open " << outfile << std::endl;
			return ;
		} 
		outf << "   oxoxoo    ooxoo\n";
		outf << " ooxoxo oo  oxoxooo\n";
		outf << "oooo xxoxoo ooo ooox\n";
		outf <<	"oxo o oxoxo  xoxxoxo\n";
		outf <<	" oxo xooxoooo o ooo\n";
		outf << "   ooo\\oo\\  /o/o\n";
		outf <<	"          \\  \\/ /\n";
		outf << "           |   /\n";
		outf << "           |  |\n";
		outf << "           | D|\n";
		outf << "           |  |\n";
		outf << "           |  |\n";
		outf << "    ______/____\\____\n";
		outf.close();
	}
}

std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm &S)
{
	return (o);
}

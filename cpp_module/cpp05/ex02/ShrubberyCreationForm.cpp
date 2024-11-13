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
	AForm::execute(executor);
	std::string	outfile = this->_target + "_shrubbery";
	std::ofstream outf;
	outf.open(outfile.c_str());
	if (outf.fail()){
		throw OpenFailException();
	} 
	outf << "   oxoxoo    ooxoo\n";
	outf << " ooxoxo oo  oxoxooo\n";
	outf << "oooo xxoxoo ooo ooox\n";
	outf <<	"oxo o oxoxo  xoxxoxo\n";
	outf <<	" oxo xooxoooo o ooo\n";
	outf << "   ooo\\oo\\  /o/o\n";
	outf <<	"       \\  \\/ /\n";
	outf << "        |   /\n";
	outf << "        |  |\n";
	outf << "        | D|\n";
	outf << "        |  |\n";
	outf << "        |  |\n";
	outf << " ______/____\\____\n";
	outf.close();	
}

std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

const char* ShrubberyCreationForm::OpenFailException::what() const throw(){
	return "\033[0;31m Error: can`t open file\033[0m";
}

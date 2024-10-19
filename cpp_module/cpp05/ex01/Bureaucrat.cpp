#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->_name = "UNKNOWN";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade){
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		this->_grade = grade;
		this->_name = name;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const& oth)
{
	this->_grade = oth._grade;
	this->_name = oth._name;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& copy){
	if (this != &copy)
	{
		this->_grade = copy._grade;
		this->_name = copy._name;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void){
}

unsigned int	Bureaucrat::getGrade(void) const{
	return this->_grade;
}

std::string Bureaucrat::getName(void) const{
	return this->_name;
}

void	Bureaucrat::decrementGrade(void){
	try
	{
		if (_grade  + 1 > 150)
			throw GradeTooLowException();
		_grade += 1;
	}
	catch(GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	Bureaucrat::incrementGrade(void){
	try
	{
		if (_grade - 1 == 0)
			throw GradeTooHighException();
				_grade--;
	}
	catch(GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
void	Bureaucrat::signForm(Form &F){
	try
	{
		if (F.getSigned() == false)
		{
			if (F.getSignLevel() > this->_grade)
				std::cout << _name << "signed" << F.getName() << std::endl;
			else
				throw GradeTooLowException();
		}
		else
			throw AlreadySigned();
	}
	catch(const std::exception& e)
	{
		std::cout << _name << "couldn't sign" << F.getName() << "because " << e.what() << "." << std::endl;
	}
	
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::AlreadySigned::what() const throw() {
    return "this form was already signed";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& B)
{
	o << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
	return o;
}

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->_name = "default";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	this->_name = name;
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
	catch(const std::exception& e)
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "\033[0;31mGrade is too low!\033[0m";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "\033[0;31mGrade is too high!\033[0m";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& B)
{
	o << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
	return o;
}

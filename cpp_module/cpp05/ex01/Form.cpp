#include "Form.hpp"

Form::Form():_name(""), _isSigned(false), _signLevel(1), _executeLevel(1){
}

Form::Form(std::string name, unsigned int sign, unsigned int execute){
	try
	{
		if (sign < 1 || execute < 1)
			throw GradeTooHighException();
		if (sign > 150 || execute > 150)
			throw GradeTooLowException();
		_name = name;
		_isSigned = false;
		_signLevel = sign;
		_executeLevel = execute;	
	}
	catch(const GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

Form::Form(const Form &F):_name(F._name), _isSigned(F._isSigned), _signLevel(F._signLevel), _executeLevel(F._executeLevel){
}

Form &	Form::operator=(const Form &copy){
	if (this != &copy){
		this->_name = copy._name;
		this->_isSigned = copy._isSigned;
		this->_signLevel = copy._signLevel;
		this->_executeLevel = copy._executeLevel;
	}
	return *this;
}

Form::~Form(){
}

void	Form::beSigned(Bureaucrat &B){
	try
	{
		if (B.getGrade() > this->_signLevel)
			throw GradeTooLowException();
		this->_isSigned = true;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << e.what() << '\n';
	}
	
}

bool	Form::getSigned(void) const{
	return _isSigned;
}

std::string	Form::getName(void) const{
	return _name;
}

unsigned int	Form::getSignLevel(void) const{
	return _signLevel;
}

unsigned int	Form::getExecuteLevel(void) const{
	return _executeLevel;
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

std::ostream& operator<<(std::ostream& o, const Form& F){

	return (o);
}
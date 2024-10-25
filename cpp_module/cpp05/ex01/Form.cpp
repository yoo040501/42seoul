#include "Form.hpp"

Form::Form():_name("default"), _isSigned(false), _signLevel(1), _executeLevel(1){
}

Form::Form(std::string name, unsigned int sign, unsigned int execute){
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
	if (sign < execute)
		throw ImproperGradeException();
	_name = name;
	_isSigned = false;
	_signLevel = sign;
	_executeLevel = execute;	
	
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
	if (B.getGrade() > this->_signLevel)
		throw GradeTooLowException();
	else if (_isSigned == false)
	{
		_isSigned = true;
		std::cout << this->getName() << " Form was signed by " << B.getName() << std::endl;
	}
	else
		throw AlreadySignedException();
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
    return "\033[0;31mGrade is too low!\033[0m";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "\033[0;31mGrade is too high!\033[0m";
}

const char* Form::AlreadySignedException::what() const throw() {
	return " \033[0;31mForm is already signed\033[0m";
}

const char* Form::ImproperGradeException::what() const throw() {
	return "\033[0;31mExecute Grade must be higher than Sign Grade\033[0m";
}

std::ostream& operator<<(std::ostream& o, const Form& F){
	o << "--------------------------------------------------------------\n";
	o << F.getName() << " form signed: " << std::boolalpha << F.getSigned() << ", signgrade: " << F.getSignLevel() << ", executegrade: " << F.getExecuteLevel() << ".\n";
	o << "--------------------------------------------------------------";
	return (o);
}

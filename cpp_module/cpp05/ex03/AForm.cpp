#include "AForm.hpp"

AForm::AForm():_name("default"), _isSigned(false), _signLevel(1), _executeLevel(1){
}

AForm::AForm(std::string name, unsigned int sign, unsigned int execute){
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

AForm::AForm(const AForm &F):_name(F._name), _isSigned(F._isSigned), _signLevel(F._signLevel), _executeLevel(F._executeLevel){
}

AForm &	AForm::operator=(const AForm &copy){
	if (this != &copy){
		this->_name = copy._name;
		this->_isSigned = copy._isSigned;
		this->_signLevel = copy._signLevel;
		this->_executeLevel = copy._executeLevel;
	}
	return *this;
}

AForm::~AForm(){
}

void	AForm::beSigned(Bureaucrat &B){
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

void	AForm::execute(Bureaucrat const& executor)const
{
	if (executor.getGrade() > this->getExecuteLevel())
		throw (GradeTooLowException());
	else if (this->getSigned() == false)
		throw (FormNotSignedException());
}

bool	AForm::getSigned(void) const{
	return _isSigned;
}

std::string	AForm::getName(void) const{
	return _name;
}

unsigned int	AForm::getSignLevel(void) const{
	return _signLevel;
}

unsigned int	AForm::getExecuteLevel(void) const{
	return _executeLevel;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "\033[0;31mGrade is too low!\033[0m";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "\033[0;31mGrade is too high!\033[0m";
}

const char* AForm::AlreadySignedException::what() const throw() {
	return " \033[0;31mForm is already signed\033[0m";
}

const char* AForm::ImproperGradeException::what() const throw() {
	return "\033[0;31mExecute Grade must be higher than Sign Grade\033[0m";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "\033[0;31mthis form is not signed!\033[0m";
}

std::ostream& operator<<(std::ostream& o, const AForm& F){
	o << "------------------------------------------------------------------------\n";
	o << F.getName() << " form signed: " << std::boolalpha << F.getSigned() << ", signgrade: " << F.getSignLevel() << ", executegrade: " << F.getExecuteLevel() << ".\n";
	o << "------------------------------------------------------------------------";
	return (o);
}

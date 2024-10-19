#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <exception>

class Bureaucrat
{
private:
	std::string 	_name;
	unsigned int	_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const& oth);
	Bureaucrat& operator=(Bureaucrat const& copy);
	~Bureaucrat();

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;
	void			incrementGrade();
	void			decrementGrade();

	class GradeTooLowException: public std::exception{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooHighException: public std::exception{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& B);

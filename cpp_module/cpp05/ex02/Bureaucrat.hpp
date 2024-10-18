#pragma once

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

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
	void			incrementGrade(unsigned int level);
	void			decrementGrade(unsigned int level);
	void			signForm(Form &F);

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

#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string		_name;
		bool			_isSigned;
		unsigned int	_signLevel;
		unsigned int	_executeLevel;

	public:
		Form();
		Form(std::string name, unsigned int sign, unsigned int execute);
		Form(const Form &F);
		Form &operator=(const Form &copy);
		~Form();

		void			beSigned(Bureaucrat &B);
		
		bool			getSigned(void) const;
		std::string		getName(void) const;
		unsigned int	getSignLevel(void) const;
		unsigned int	getExecuteLevel(void) const;

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
	};

std::ostream& operator<<(std::ostream& o, const Form& F);

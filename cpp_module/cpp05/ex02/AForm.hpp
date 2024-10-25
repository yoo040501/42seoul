#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime> 
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string		_name;
		bool			_isSigned;
		unsigned int	_signLevel;
		unsigned int	_executeLevel;

	public:
		AForm();
		AForm(std::string name, unsigned int sign, unsigned int execute);
		AForm(const AForm &F);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		void			beSigned(Bureaucrat &B);
		virtual void	execute(Bureaucrat const & executor)const = 0;
		
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

		class AlreadySignedException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
		
		class ImproperGradeException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
	};

std::ostream& operator<<(std::ostream& o, const AForm& F);

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void){
	srand(time(NULL));

	try
	{
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 20);

		Intern  someRandomIntern;
		AForm*   rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		b.executeForm(*rrf);	
		b.signForm(*rrf);	
		b.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

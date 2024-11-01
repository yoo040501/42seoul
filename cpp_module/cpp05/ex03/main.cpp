#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){
	srand(time(NULL));

	try
	{
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 20);

		RobotomyRequestForm one("one");

		std::cout << one << std::endl;

		b.executeForm(one);	
		b.signForm(one);	
		b.executeForm(one);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

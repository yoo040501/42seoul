#include "Bureaucrat.hpp"

int main(void){
	try
	{
		try
		{
			Bureaucrat a("a", 200);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		Bureaucrat b("b", 150);
		Bureaucrat c("c", 1);

		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << std::endl;

		b.incrementGrade();
		c.decrementGrade();
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

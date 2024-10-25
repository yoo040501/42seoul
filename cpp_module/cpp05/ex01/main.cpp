#include "Bureaucrat.hpp"

int main(void){
	try
	{
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 30);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		Form one("one", 20, 7);

		std::cout << one << std::endl;

		b.signForm(one);	

		std::cout << one << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

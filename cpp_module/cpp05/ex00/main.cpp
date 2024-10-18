#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat	a("a", 500);
	Bureaucrat	b("b", 123);

	a.decrementGrade(5);
	std::cout << a << std::endl;
}

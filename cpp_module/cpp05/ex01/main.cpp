#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat	a("a", 0);
	Bureaucrat	b("b", 123);

	a.decrementGrade();
	std::cout << a << std::endl;
}

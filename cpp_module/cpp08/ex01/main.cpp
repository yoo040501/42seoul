#include "Span.hpp"
#include <list>

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(2147483647);
		sp.addNumber(3);
		sp.addNumber(-123123);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::list<int> a;
		a.push_back(1);
		a.push_back(4);
		a.push_back(5);
		a.push_back(2);
		a.push_back(12);
		// a.push_back(12);
		Span sp = Span(5);
		sp.addNumber(a.begin(), a.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

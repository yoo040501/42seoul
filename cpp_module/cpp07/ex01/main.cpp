#include "iter.hpp"

void	print(const char a)
{
	std::cout << a << std::endl;
}

void	plus(char& a)
{
	a += 1;
}

int main( void ) 
{ 
	char test[5] = {'a', 'b', 'c', 'd', 'e'};

	for (int i = 0; i < 5; i++)
		std::cout << test[i] << ' ';
	std::cout << std::endl;

	iter(test, 5, plus);
	for (int i = 0; i < 5; i++)
		std::cout << test[i] << ' ';
	std::cout << std::endl;

	iter(test, 5, print);
	return 0;
}

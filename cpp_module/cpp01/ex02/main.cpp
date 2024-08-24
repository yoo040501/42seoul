#include <iostream>

int	main(void)
{
	std::string word = "HI THIS IS BRAIN";
	std::string *stringPTR = &word;
	std::string &stringREF = word;

	std::cout << "Memory address of string: " << &word << '\n';
	std::cout << "Memory address held by stringPTR: " << &stringPTR << '\n';
	std::cout << "Memory address held by stringREF: " << &stringREF << '\n';

	std::cout << "Value of the string: " << word << std::endl;
	std::cout << "Value pointed by stringPTR: " << stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;
	return (0);
}


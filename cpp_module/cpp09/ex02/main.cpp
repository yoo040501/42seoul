#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 3)
			throw std::invalid_argument("Error: input");
		PmergeMe per(argv, argc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

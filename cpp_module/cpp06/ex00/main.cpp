#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc >= 3 || argc == 1)
			throw std::invalid_argument("한개의 인자만 입력!");
		ScalarConverter::convert(argv[1]);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

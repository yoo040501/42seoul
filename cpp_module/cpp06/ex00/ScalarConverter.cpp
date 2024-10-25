#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string word){
	try
	{
		if (word.length())
		throw std::overflow_error("");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
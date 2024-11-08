#pragma once

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &S);
		ScalarConverter& operator=(ScalarConverter const &copy);
		~ScalarConverter();
	public:
		static void	convert(std::string word);
};

#pragma once

#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &S);
		ScalarConverter& operator=(ScalarConverter const &copy);
		~ScalarConverter();
	public:
		static void	convert(char *word);
};

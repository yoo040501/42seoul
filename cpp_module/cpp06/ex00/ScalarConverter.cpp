#include "ScalarConverter.hpp"

int	isNumber(std::string str)
{
	size_t i = 0;
	size_t type = 1;

	bool hasDecimal = false;

	if (str[0] == '-' || str[0] == '+')	i = 1;

    for (; i < str.length(); ++i) {
        if (str[i] == '.') {
            if (hasDecimal)
				return false;
            hasDecimal = true;
        }
		else if (!std::isdigit(str[i])) {
			if (i == str.length() - 1 && str[i] == 'f')
				type = 2;
			else
            	return false;
        }
    }
	if (str[str.length() - 1] == '.')
		return false;
	if (hasDecimal == true && str[str.length() - 1] != 'f')
    	type = 3;
	return type;
}

void	changeInt(std::string str) //int형에서 변환
{
	std::stringstream tmp(str);
	int	num;

	if (tmp >> num)
	{
		std::cout.precision(1);
		std::cout << std::fixed;

		std::cout << "char: ";
		if (isprint(static_cast<char>(num)) || num < 255)
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (static_cast<float>(num) > INT_MAX || static_cast<float>(num) < INT_MIN)
			std::cout << " impossible" << std::endl;
		else
			std::cout << num << std::endl;
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;

		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
}

void	changeFloat(std::string str)
{
	str.erase(str.length() - 1);
	std::stringstream tmp(str);
	float	num;

	if (tmp >> num)
	{
		std::cout.precision(1);
		std::cout << std::fixed;

		std::cout << "char: ";
		if (isprint(static_cast<char>(num)))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: ";
		if (num > INT_MAX || num < INT_MIN)
			std::cout << " impossible" << std::endl;
		else
			std::cout << static_cast<int>(num) << std::endl;

		std::cout << "float: ";
		if (num > std::numeric_limits<float>::max())
			std::cout << "+inf";
		else if (num < -std::numeric_limits<float>::max())
			std::cout << "-inf" ;
		else
			std::cout << num;
		std::cout << "f" << std::endl;

		std::cout << "double: ";
		if (num > std::numeric_limits<double>::max())
			std::cout << "+inf" << std::endl;
		else if (num < -std::numeric_limits<double>::max())
			std::cout << "-inf" << std::endl;
		else
			std::cout << static_cast<double>(num) << std::endl;
	}
}

void	ScalarConverter::convert(char *word){
	std::string str(word);
	size_t		getType = isNumber(str);
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		if (std::isprint(str[0]))
		{
			std::cout.precision(1);
			std::cout << std::fixed;
			std::cout << "char: '" << str << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
		}
		else
			throw std::invalid_argument("char: 한개의 문자만 입력하세요");
	}

	else if (str == "+inff" || str == "-inff" || str == "nanf"){
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: ";
		if (str == "+inff")
			std::cout << std::numeric_limits<float>::max() << std::endl;
		else if (str == "-inff")
			std::cout << std::numeric_limits<float>::min() << std::endl;
		else
			std::cout << "nan" << std::endl;
	}
	else if (str == "+inf" || str == "-inf" || str == "nan")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	else if (getType)
	{
		std::stringstream tmp(str);
		if (getType == 1)
			changeInt(str);
		else if (getType == 2)
			changeFloat(str);
		else
		{
			double	num;
			if (tmp >> num)
			{
				std::cout << "char: ";
				if (isprint(static_cast<char>(num)) || num < 255)
					std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
				else
					std::cout << "Non displayable" << std::endl;

				std::cout << "int: ";
				if (num > INT_MAX || num < INT_MIN)
					std::cout << " impossible" << std::endl;
				else
					std::cout << static_cast<int>(num) << std::endl;

				std::cout << "float: ";
				if (num > std::numeric_limits<float>::max())
					std::cout << "+inf";
				else if (num < -std::numeric_limits<float>::max())
					std::cout << "-inf" ;
				else
					std::cout << static_cast<float>(num);
				std::cout << "f" << std::endl;

				std::cout << "double: ";
				if (num > std::numeric_limits<double>::max())
					std::cout << "+inf" << std::endl;
				else if (num < -std::numeric_limits<double>::max())
					std::cout << "-inf" << std::endl;
				else
					std::cout << static_cast<double>(num) << std::endl;
			}
		}
	}
	else
		throw	std::invalid_argument("잘못된 입력");
}

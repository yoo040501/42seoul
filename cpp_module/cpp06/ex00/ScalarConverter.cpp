#include "ScalarConverter.hpp"

int	isNumber(std::string str)
{
	size_t i = 0;
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
				continue;
			else
            	return false;
        }
    }
	if (str[str.length() - 1] == '.')
		return false;
	if (hasDecimal == true)
    	return 2;
	return 1;
}

void	ScalarConverter::convert(char *word){
	std::string str(word);

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
	else if (isNumber(str))
	{
		if (str[str.length() - 1] == 'f')
			str.erase(std::find(str.begin(),str.end(), 'f'));
		std::stringstream tmp(str);
		double	num;
		if (tmp >> num)
		{
			if (isNumber(str) == 1){
				std::cout.precision(1);
				std::cout << std::fixed;}

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
			else if (num < std::numeric_limits<float>::lowest())
				std::cout << "-inf" ;
			else
				std::cout << static_cast<float>(num);
			std::cout << "f" << std::endl;

			std::cout << "double: ";
			if (num > std::numeric_limits<double>::max())
				std::cout << "+inf" << std::endl;
			else if (num < std::numeric_limits<double>::lowest())
				std::cout << "-inf" << std::endl;
			else
				std::cout << num << std::endl;
		}
	}
	else
		throw	std::invalid_argument("잘못된 입력");
}

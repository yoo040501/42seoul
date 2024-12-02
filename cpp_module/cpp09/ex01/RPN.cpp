#include "RPN.hpp"

RPN::RPN(char *av){
	cal(av);
}

RPN::~RPN(){}

bool RPN::isFlag(const char c)
{
	const char flag[4] = {'+', '-', '/', '*'};
	for (int i=0;i<4;i++)
	{
		if (c == flag[i])
			return true;
	}
	return false;
}

bool	RPN::exec(std::stack<long> &save, char c)
{
	long	num1, num2;

	if (save.size() <= 1)
		return false;
	num2 = save.top();
	save.pop();
	num1 = save.top();
	save.pop();

	switch (c)
	{
	case '+':
		save.push(num1 + num2);
		break;
	case '-':
		save.push(num1 - num2);
		break;
	case '*':
		save.push(num1 * num2);
		break;
	case '/':
		if(num2 == 0)
			return false;
		save.push(num1 / num2);
		break;
	default:
		std::cout << "aa\n";
		return false;
	}
	return true;
}

void    RPN::cal(char* input)
{
    std::string str(input);
    std::string buffer;
    std::istringstream iss(str);
    std::stack<long> save;

    while (getline(iss, buffer, ' ')){
        if (buffer.length() == 1){
            if (isdigit(buffer[0]))
        		save.push(atol(buffer.c_str()));
			else if (isFlag(buffer[0])){
				if (exec(save, buffer[0]) == false)
					throw std::invalid_argument("Error");
				}
			else
				throw std::invalid_argument("Error");
        }
        else if (buffer.length() == 0)
			continue;
		else
            throw std::invalid_argument("Error");
    }
	if (save.size() != 1)
		throw std::invalid_argument("Error");
	std::cout << save.top() << std::endl;
	save.pop();
}

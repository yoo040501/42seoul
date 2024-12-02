#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <string>


void    cal(char *input);

class RPN
{
	private:
		RPN();
		RPN(RPN const& copy);
		RPN& operator=(RPN const& oth);
		void    cal(char* input);
		bool	exec(std::stack<long> &save, char c);
		bool 	isFlag(const char c);
	public:
		RPN(char *av);
		~RPN();
};

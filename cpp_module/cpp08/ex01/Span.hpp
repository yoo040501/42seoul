#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int>	arr;
		int					len;
	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span& operator=(const Span &S);
		~Span();

		void	addNumber(int num);
		int		shortestSpan(void);
		int		longestSpan(void);
};

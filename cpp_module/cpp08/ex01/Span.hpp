#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

		void		addNumber(int num);
		long		shortestSpan(void);
		long		longestSpan(void);
		template <typename Iterator>
		void	addNumber(Iterator begin, Iterator end){
			int size= static_cast<int>(std::distance(begin, end));
			if (len < size)
				throw std::out_of_range("out_of_range");
			while (begin != end)
			{
				addNumber(*begin);
				begin++;
			}
		}
};

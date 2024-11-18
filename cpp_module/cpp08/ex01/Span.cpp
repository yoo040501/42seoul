#include "Span.hpp"

Span::Span(unsigned int N) : len(N){	
}

Span::Span(const Span &copy) : arr(copy.arr), len(copy.len){
}

Span&	Span::operator=(const Span &S)
{
	if (this != &S)
    {
        arr = S.arr;
		len = S.len;
    }
    return *this;
}
Span::~Span(){}

void	Span::addNumber(int num){
	if (static_cast<int>(arr.size()) > len)
		throw	std::out_of_range("Error: out_of_range");
	arr.push_back(num);
}

long	Span::longestSpan(void){
	long	max = 0;
	std::vector<int>tmp = arr;

	if (arr.size() < 2) {
		throw std::out_of_range("Error: 비교 숫자가 없음");
    }
	std::sort(tmp.begin(), tmp.end());
	max = static_cast<long>(tmp[tmp.size() - 1]) - static_cast<long>(tmp[0]);
	return max;
}

long	Span::shortestSpan(void){
	long	min = INT_MAX;
	std::vector<int>tmp = arr;
	if (arr.size() < 2) {
		throw std::out_of_range("Error: 비교 숫자가 없음");
    }
	std::sort(tmp.begin(), tmp.end(), std::greater<int>());
	for (size_t i=0;i<tmp.size() - 1;i++)
	{
		if (min > static_cast<long>(tmp[i]) - static_cast<long>(tmp[i + 1]))
			min = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i + 1]);
	}
	return min;
}

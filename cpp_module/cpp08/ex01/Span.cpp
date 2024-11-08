#include "Span.hpp"

Span::Span(unsigned int N) : len(N){	
}

Span::Span(const Span &copy) : arr(copy.arr){
}

Span&	Span::operator=(const Span &S)
{
	if (this != &S)
    {
        arr = S.arr;
    }
    return *this;
}
Span::~Span(){}

void	Span::addNumber(int num){
	if (static_cast<int>(arr.size()) > len)
		throw	std::out_of_range("Error: out_of_range");
	arr.push_back(num);
}

int	Span::longestSpan(void){
	int	max = 0;
	std::vector<int>tmp = arr;

	if (arr.size() < 2) {
		throw std::out_of_range("Error: 비교 숫자가 없음");
    }
	std::stable_sort(tmp.begin(), tmp.end());
	max = tmp[tmp.size() - 1] - tmp[0];
	return max;
}

int	Span::shortestSpan(void){
	int	min = INT_MAX;
	std::vector<int>tmp = arr;
	if (arr.size() < 2) {
		throw std::out_of_range("Error: 비교 숫자가 없음");
    }
	std::stable_sort(tmp.begin(), tmp.end(), std::greater<int>());
	for (size_t i=0;i<tmp.size() - 1;i++)
	{
		if (min > tmp[i] - tmp[i + 1])
			min = tmp[i] - tmp[i + 1];
	}
	return min;
}

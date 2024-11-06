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

	if (arr.size() < 2) {
		throw std::out_of_range("Error: 비교 숫자가 없음");
    }
	std::stable_sort(arr.begin(), arr.end());
	max = arr[arr.size() - 1] - arr[0];
	return max;
}

int	Span::shortestSpan(void){
	int	min = INT_MAX;

	if (arr.size() < 2) {
		throw std::out_of_range("Error: 비교 숫자가 없음");
    }
	std::stable_sort(arr.begin(), arr.end());
	for (size_t i=0;i<arr.size() - 1;i++)
	{
		if (min > abs(arr[i] - arr[i + 1]))
			min = abs(arr[i] - arr[i + 1]);
	}
	return min;
}

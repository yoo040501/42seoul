#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int len)
{
	for (int i=1;i<len;i++)
		getNum(av[i]);
	printElement();
	alreadySorted();
}

PmergeMe::~PmergeMe(){
	while (!num.empty())
		num.pop_back();
	num.clear();
}

void	PmergeMe::alreadySorted(){
	std::vector<int> tmp = num;

	sort(tmp.begin(), tmp.end());
	for (size_t i=0;i<tmp.size();i++){
		if (tmp[i] != num[i])
			return ;
	}
	throw std::invalid_argument("Already sorted");
}

void	PmergeMe::printElement()
{
	// std::cout << "element ";
	for (size_t i=0;i < num.size();i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::getNum(char *str)
{
	int		number;

	number = atoi(str);
	if (number <= 0)
		throw std::invalid_argument("It is not positive number");
	else
		num.push_back(number);
}

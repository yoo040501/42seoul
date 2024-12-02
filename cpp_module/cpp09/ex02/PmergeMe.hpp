#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <climits>
#include <cmath>
#include <deque>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(PmergeMe const& copy);
		PmergeMe& operator=(PmergeMe const& oth);
		std::vector<int> num;
		std::vector<std::pair<int, int> > mainChain;
		std::vector<std::pair<int, int> > subChain;
		void	getNum(char *str);
		void	printElement();
		void	alreadySorted();

	public:
		PmergeMe(char **av, int len);
		~PmergeMe();
};

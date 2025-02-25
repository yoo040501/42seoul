#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
#include <climits>
#include <cmath>
#include <deque>
#include <ctime>
#include <cstring>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(PmergeMe const& copy);
		PmergeMe& operator=(PmergeMe const& oth);
		std::vector<int> data_vec;
		std::deque<int> data_deq;
		std::list<int> data_list;
		void	getData(char *str);
		void	printElement(std::vector<int> sorted_vector, std::list<int> sorted_list);
		void	alreadySorted();
		void	printTime(clock_t vec, clock_t lst);
		
		void	sortVec(std::vector<int> &sorted_vector);
		void	sortDeq(std::deque<int> &sorted_deq);
		void	sortList(std::list<int> &sorted_list);

	public:
		PmergeMe(char **av, int len);
		~PmergeMe();
};

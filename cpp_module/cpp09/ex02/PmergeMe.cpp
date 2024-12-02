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



void PmergeMe::mergeVec(int start, int mid, int end)
{
    int left_size = mid - start + 1;
    int right_size = end - mid;
    std::vector<int> left(left_size);
    std::vector<int> right(right_size);

    int i = 0;
    while (i < left_size)
    {
        left[i] = this->vec[start + i];
        i++;
    }
    int j = 0;
    while (j < right_size)
    {
        right[j] = this->vec[mid + 1 + j];
        j++;
    }
    i = 0;
    j = 0;
    int idx = start;
    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            this->vec[idx] = left[i];
            i++;
        }
        else
        {
            this->vec[idx] = right[j];
            j++;
        }
        idx++;
    }

    while (i < left_size)
    {
        this->vec[idx] = left[i];
        i++;
        idx++;
    }

    while (j < right_size)
    {
        this->vec[idx] = right[j];
        j++;
        idx++;
    }
}

void PmergeMe::InsertVec(int start, int end)
{
    for (int i = start+1; i <= end; i++)
    {
        int key = this->vec[i];
        int j = i - 1; 
        while (j >= start && this->vec[j] > key)
        {
            this->vec[j + 1] = this->vec[j];
            j--;
        }
        this->vec[j + 1] = key;
    }
}

void PmergeMe::mergeInsertVec(int start, int end)
{
    if (start < end)
    {
        if (end - start <= 10)
            InsertVec(start, end);
        else
        {
            int mid = start + (end - start) / 2;
            mergeInsertVec(start, mid);
            mergeInsertVec(mid+1, end);
            mergeVec(start, mid, end);
        }
    }
}

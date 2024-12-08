#include "PmergeMe.hpp"

void sortVector(std::vector<int> data);

PmergeMe::PmergeMe(char **av, int len)
{
	for (int i=1;i<len;i++)
		getNum(av[i]);
	printElement();
	alreadySorted();
	sortVector(num);
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

std::vector<std::pair<int, int> > makePairsVector(std::vector<int> data) {
  int size = data.size() % 2 == 1 ? data.size() - 1 : data.size();
  std::vector<std::pair<int, int> > mainChain;

  if (data.size() % 2 == 1) data.push_back(0);
  for (int i = 0; i < size; i += 2) {
    if (data[i] > data[i + 1]) {
      mainChain.push_back(std::make_pair(data[i], data[i + 1]));
    }
	else {
      mainChain.push_back(std::make_pair(data[i + 1], data[i]));
    }
  }
  return mainChain;
}

void binarySearchVector(std::vector<int> &vector, int element, int left, int right) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (vector.at(mid) <= element) {
      left = mid + 1;
    } else if (vector.at(mid) > element) {
      right = mid - 1;
    }
  }
  vector.insert(vector.begin() + left, element);
}

void mergeVector(std::vector<std::pair<int, int> >&vector, std::vector<std::pair<int, int> >&left_vector, std::vector<std::pair<int, int> >&right_vector) {
  int i = 0;
  int j = 0;
  int k = 0;
  int left_size = left_vector.size();
  int right_size = right_vector.size();

  while (i < left_size && j < right_size) {
    if (left_vector[i].first <= right_vector[j].first) {
      vector[k++] = left_vector[i++];
    } else {
      vector[k++] = right_vector[j++];
    }
  }
  while (i < left_size) {
    vector[k++] = left_vector[i++];
  }
  while (j < right_size) {
    vector[k++] = right_vector[j++];
  }
}

void MergeSortVector(std::vector<std::pair<int, int> > &mainChain, int left, int right) {
  if (left >= right)
    return;
  int mid = left + (right - left) / 2;
  std::vector<std::pair<int, int> > left_vector(mainChain.begin() + left, mainChain.begin() + mid + 1);
  std::vector<std::pair<int, int> > right_vector(mainChain.begin() + mid + 1, mainChain.begin() + right + 1);
  MergeSortVector(left_vector, 0, left_vector.size() - 1);
  MergeSortVector(right_vector, 0, right_vector.size() - 1);
  mergeVector(mainChain, left_vector, right_vector);
}

std::vector<int> sortPairVector(std::vector<int> vector, std::vector<std::pair<int, int> > mainChain) {
  MergeSortVector(mainChain, 0, mainChain.size() - 1);
  std::vector<int> sorted_vector;

  for (int i = 0; i < mainChain.size(); i++) {
    sorted_vector.push_back(mainChain[i].first);
  }
  sorted_vector.insert(sorted_vector.begin(), mainChain[0].second);
  for (int i = 1; i < mainChain.size(); i++) {
    size_t right = std::find(
        sorted_vector.begin(),
        sorted_vector.end(),
        mainChain[i].first
    ) - sorted_vector.begin();
    binarySearchVector(sorted_vector, mainChain[i].second, 0, right - 1);
  }
  if (vector.size() % 2 == 1) {
    binarySearchVector(
        sorted_vector,
        vector[vector.size() - 1],
        0,
        static_cast<int>(sorted_vector.size()) - 1
    );
  }
  return sorted_vector;
}

void sortVector(std::vector<int> data) {
  std::vector<std::pair<int, int> > mainChain;
  std::vector<int> sorted_vector;

  mainChain = makePairsVector(data);
  sorted_vector = sortPairVector(data, mainChain);

  	for (size_t i=0;i < sorted_vector.size();i++)
		std::cout << sorted_vector[i] << " ";
	std::cout << std::endl;
}
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int len)
{
	clock_t	vec_start, vec_finish, list_start, list_finish;
	std::vector<int> sorted_vector;
	// std::deque<int> sorted_deque;
	std::list<int> sorted_list;

	for (int i=1;i<len;i++)
		getData(av[i]);
	alreadySorted(); // 이미 정렬되있다면 에러

	vec_start = clock();
	sortVec(sorted_vector);
	vec_finish = clock();

	// deq_start = clock();
	// sortDeq(sorted_deque);
	// deq_finish = clock();

	list_start = clock();
	sortList(sorted_list);
	list_finish = clock();
	
	printElement(sorted_vector, sorted_list);
	printTime(vec_finish - vec_start, list_finish - list_start);
}

PmergeMe::~PmergeMe(){
}

void	PmergeMe::printTime(clock_t vec, clock_t lst)
{
	std::cout << "Time to process a range of " << data_vec.size() << " elements with std::vector : "
				<< static_cast<double>(vec) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	// std::cout << "Time to process a range of " << data_deq.size() << " elements with std::deque : "
	// 		<< static_cast<double>(deq) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	std::cout << "Time to process a range of " << data_list.size() << " elements with std::list : "
		<< static_cast<double>(lst) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}

void	PmergeMe::alreadySorted(){
	for (size_t i = 1; i < data_vec.size(); ++i) {
        if (data_vec[i - 1] > data_vec[i]) return;
    }
	throw std::invalid_argument("\033[0;31mAlready sorted...\033[0;0m");
}

void	PmergeMe::printElement(std::vector<int> sorted_vector, std::list<int> sorted_list)
{
	std::cout << "Before: ";
	for (size_t i=0;i < data_vec.size();i++)
		std::cout << data_vec[i] << " ";
	std::cout << std::endl;

	std::vector<int> tmp = data_vec;
	sort(tmp.begin(), tmp.end());
	for (size_t i=0;i<tmp.size();i++){
		if (tmp[i] != sorted_vector[i])
			throw std::invalid_argument("\033[0;31msort fail!\033[0;0m");
	}

	// std::deque<int> tmp_deq = data_deq;
	// sort(tmp_deq.begin(), tmp_deq.end());
	// for (size_t i=0;i<tmp_deq.size();i++){
	// 	if (tmp_deq[i] != sorted_deque[i])
	// 		throw std::invalid_argument("\033[0;31msort fail!\033[0;0m");
	// }

	std::list<int> tmp_list = data_list;
	tmp_list.sort();
	std::list<int>::iterator it1 = sorted_list.begin();
	std::list<int>::iterator it2 = tmp_list.begin();

	for (; it1 != sorted_list.end(); ++it1, ++it2) {
		if (*it1 != *it2) {
			throw std::invalid_argument("\033[0;31msort fail!\033[0;0m");
		}
	}
	
	std::cout << "After: ";
	for (size_t i=0;i < sorted_vector.size();i++)
		std::cout << sorted_vector[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::getData(char *str)
{
	long	number;

	for (size_t i=0;i<strlen(str);i++)
	{
		if (!isdigit(str[i]))
			throw std::invalid_argument("It is not number");
	}
	number = atol(str);
	if (number <= 0 || number > INT_MAX)
		throw std::invalid_argument("It is not positive number");
	else{
		data_vec.push_back(static_cast<int>(number));
		data_deq.push_back(static_cast<int>(number));
		data_list.push_back(static_cast<int>(number));
	}
}

size_t	getJacobsthalNum(size_t i, size_t *beforeJacobNum)
{
	int	t = 2;
	size_t	JacobNum;
	*beforeJacobNum = 0;

	while (1)
	{
		JacobNum = (pow(2, t) - pow(-1, t)) / 3;
		if (i < JacobNum)
			break ;
		t++;
		*beforeJacobNum = JacobNum;
	}
	return JacobNum;
}

std::vector<size_t> saveJacobsthal(size_t n) {
    std::vector<size_t> order;
    size_t start = 0;

    while (start < n) {
        size_t beforeJacob = 0;
        size_t J = getJacobsthalNum(start, &beforeJacob);
        size_t groupSize = J - beforeJacob;
        if (start + groupSize > n)
            groupSize = n - start;
        //역순으로 삽입 (마지막 인덱스부터 시작)
        for (size_t i = start + groupSize; i > start; i--) {
            order.push_back(i - 1);
        }
        start += groupSize;
    }
    return order;
}

int recursiveBinarySearchVec(const std::vector<int>& sorted, int value, int left, int right) {
    if (left > right)
        return left;
    int mid = left + (right - left) / 2;
    if (value < sorted[mid])
        return recursiveBinarySearchVec(sorted, value, left, mid - 1);
    else
        return recursiveBinarySearchVec(sorted, value, mid + 1, right);
}

std::vector<int> recursiveInsertVec(const std::vector<int>& sorted, int value) {
    int index = recursiveBinarySearchVec(sorted, value, 0, static_cast<int>(sorted.size()) - 1);
    std::vector<int> result(sorted);

    result.insert(result.begin() + index, value);
    return result;
}

std::vector<int> fordJohnsonRecursiveVec(const std::vector<int>& data) {
    if (data.size() <= 1)
        return data;

    if (data.size() == 2) {
        std::vector<int> result;
        if (data[0] <= data[1]) {
            result.push_back(data[0]);
            result.push_back(data[1]);
        } else {
            result.push_back(data[1]);
            result.push_back(data[0]);
        }
        return result;
    }
    
    std::vector<int> A; // 각 쌍의 큰 값 (main chain)
    std::vector<int> B; // 각 쌍의 작은 값 (pending)

    size_t n = data.size();
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (data[i] < data[i + 1]) {
            A.push_back(data[i + 1]);
            B.push_back(data[i]);
        } else {
            A.push_back(data[i]);
            B.push_back(data[i + 1]);
        }
    }
    // 홀수인 경우 마지막 원소를 pending에 추가
    if (n % 2 == 1)
        B.push_back(data[n - 1]);
    
    // main Chain 끝까지 정렬
    std::vector<int> sortedA = fordJohnsonRecursiveVec(A);
    
    // pending 삽입 순서 -> 야콥스탈 수
    std::vector<size_t> insertionOrder = saveJacobsthal(B.size());
    
    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t idx = insertionOrder[i];
        sortedA = recursiveInsertVec(sortedA, B[idx]);
    }
    
    return sortedA;
}


void PmergeMe::sortVec(std::vector<int> &sorted_vector) {
	sorted_vector = fordJohnsonRecursiveVec(data_vec);
}


std::list<size_t> saveJacobsthalList(size_t n) {
    std::list<size_t> order;
    size_t start = 0;

    while (start < n) {
        size_t beforeJacob = 0;
        size_t J = getJacobsthalNum(start, &beforeJacob);
        size_t groupSize = J - beforeJacob;
        if (start + groupSize > n)
            groupSize = n - start;
        //역순으로 삽입 (마지막 인덱스부터 시작)
        for (size_t i = start + groupSize; i > start; i--) {
            order.push_back(i - 1);
        }
        start += groupSize;
    }
    return order;
}

std::list<int>::iterator listBinarySearchHelper(std::list<int>& sorted, int value,
                                                  std::list<int>::iterator begin,
                                                  std::list<int>::iterator end, int n) {
    if (n <= 0) return begin;
    int midIndex = n / 2;
    std::list<int>::iterator mid = begin;
    std::advance(mid, midIndex);
    if (value < *mid) {
        return listBinarySearchHelper(sorted, value, begin, mid, midIndex);
    } else {
        std::list<int>::iterator next = mid;
        ++next;
        return listBinarySearchHelper(sorted, value, next, end, n - midIndex - 1);
    }
}

std::list<int>::iterator recursiveBinarySearchList(std::list<int>& sorted, int value) {
    int n = static_cast<int>(sorted.size());
    return listBinarySearchHelper(sorted, value, sorted.begin(), sorted.end(), n);
}

void recursiveInsertList(std::list<int>& sorted, int value) {
    std::list<int>::iterator pos = recursiveBinarySearchList(sorted, value);
    sorted.insert(pos, value);
}

std::list<int> fordJohnsonRecursiveList(const std::list<int>& data) {
    if (data.size() <= 1)
        return data;

    if (data.size() == 2) {
        std::list<int> result;
        std::list<int>::const_iterator it = data.begin();

        int first = *it;
        ++it;
        int second = *it;

        if (first <= second) {
            result.push_back(first);
            result.push_back(second);
        } else {
            result.push_back(second);
            result.push_back(first);
        }
        return result;
    }
    
    std::list<int> A;
    std::list<int> B;
    std::list<int>::const_iterator it = data.begin();
    while (it != data.end()) {
        int first = *it;
        ++it;
        if (it != data.end()) {
            int second = *it;
            ++it;
            if (first < second) {
                A.push_back(second);
                B.push_back(first);
            } else {
                A.push_back(first);
                B.push_back(second);
            }
        } else {
            // 홀수인 경우, 마지막 원소는 pending에 추가.
            B.push_back(first);
        }
    }
    std::list<int> sortedA = fordJohnsonRecursiveList(A); //계속 정렬
    std::list<size_t> insertionOrder = saveJacobsthalList(B.size()); 
    for (size_t i = 0; i < insertionOrder.size(); i++) {
		std::list<size_t>::const_iterator ite = insertionOrder.begin();
        size_t idx = *ite + i;
		std::list<int>::const_iterator it = B.begin();
    	std::advance(it, idx);
        int value = *it;
        recursiveInsertList(sortedA, value);
    }
    
    return sortedA;
}

void	PmergeMe::sortList(std::list<int> &sort_list){
	sort_list = fordJohnsonRecursiveList(data_list);
}

// void binarySearchDeq(std::deque<int> &sorted, int b, int left, int right) {
//   while (left <= right) {
//     int mid = left + (right - left) / 2;
//     if (sorted[mid] <= b){
//       left = mid + 1;}
// 	else if (sorted[mid] > b){
//       right = mid - 1;}
//   }
//   sorted.insert(sorted.begin() + left, b);
// }
// 
// void mergeSortDeq(std::deque<std::pair<int, int> > &mainChain, int left, int right) {
// 	if (left >= right)
// 		return;
// 	int mid = left + (right - left) / 2;
//     // 왼쪽 및 오른쪽 반을 재귀적으로 정렬
//     mergeSortDeq(mainChain, left, mid);
//     mergeSortDeq(mainChain, mid + 1, right);
// 
//     // 병합 단계
//     int i = left;
//     int j = mid + 1;
//     int k = 0;
//     std::deque<std::pair<int, int> > temp(right - left + 1);
// 
//     // 왼쪽과 오른쪽 리스트를 병합
//     while (i <= mid && j <= right) {
//         if (mainChain[i].first <= mainChain[j].first)
//             temp[k++] = mainChain[i++];
// 		else {
//             temp[k++] = mainChain[j++];}
//     }
//     // 왼쪽 리스트의 남은 요소 복사
//     while (i <= mid) {
//         temp[k++] = mainChain[i++];
//     }
//     // 오른쪽 리스트의 남은 요소 복사
//     while (j <= right) {
//         temp[k++] = mainChain[j++];
//     }
//     // 병합된 결과를 원래 리스트에 복사
//     for (size_t l = 0; l < temp.size(); ++l) {
//         mainChain[left + l] = temp[l];
//     }
// }
// 
// std::deque<int> mergeInsertionDeque(std::deque<int> data, std::deque<std::pair<int, int> > mainChain) {
//   mergeSortDeq(mainChain, 0, mainChain.size() - 1);
//   std::deque<int> sorted_deque;
//   
//   for (size_t i = 0; i < mainChain.size(); i++) {
//     sorted_deque.push_back(mainChain[i].first);
//   }
//   sorted_deque.insert(sorted_deque.begin(), mainChain[0].second);
//   size_t	idx = 1;
// 
//   for (size_t i = 1; i < mainChain.size(); i++) {       
// 	size_t beforeJacobNum = 1;
// 	size_t k = getJacobsthalNum(i, &beforeJacobNum) - 1;
// 	if (k > mainChain.size() - 1) // JacobNum보다 사이즈가 작으면 사이즈부터 시작 ex) JacobNum = 11, mainChain.size = 8 -> 8부터 시작
// 		k = mainChain.size() - 1;
// 	i = k;
// 	for (; k >= beforeJacobNum  && k != SIZE_MAX; k--)
// 	{
// 		// mainChain에서 a값 위치 찾아서 이진탐색할 b 오른쪽 범위 설정 (1 3 4 5 6 6 7 10) 6을 찾을때 처음으로 보는 6까지 이진탐색을 하면 됨
// 		size_t right = k + idx;
// 		binarySearchDeq(sorted_deque, static_cast<int>(mainChain[k].second), 0, static_cast<int>(right) - 1);
// 		idx++;
// 	}
//   }
//   if (data.size() % 2 == 1) {
//     binarySearchDeq(sorted_deque, data[data.size() - 1], 0, static_cast<int>(sorted_deque.size()) - 1);
//   }
//   return sorted_deque;
// }
// 
// void PmergeMe::sortDeq(std::deque<int> &sorted_deq) {
//   std::deque<std::pair<int, int> > mainChain;
// 
// 	for (size_t i = 0; i + 1 < data_deq.size(); i += 2){
// 		if (data_deq[i] < data_deq[i + 1])
// 			mainChain.push_back(std::make_pair(data_deq[i + 1], data_deq[i]));
// 		else
// 			mainChain.push_back(std::make_pair(data_deq[i], data_deq[i + 1]));
// 	}
// 	sorted_deq = mergeInsertionDeque(data_deq, mainChain);
// }
// 
// void binarySearchList(std::list<int> &sorted, int b, std::list<int>::iterator left, std::list<int>::iterator right) {
// 	while (left != right) {
//         std::list<int>::iterator mid = left;
//         std::advance(mid, std::distance(left, right) / 2);
// 
//         if (*mid <= b) {
//             left = ++mid;
//         } else if (*mid > b){
//             right = mid;
//         }
//     }
//     sorted.insert(left, b);
// }
// 
// void mergeSortList(std::list<std::pair<int, int> > &mainChain) {
//    if (mainChain.size() <= 1)
//         return;
// 
//     // 리스트를 두 개로 나누기
//     std::list<std::pair<int, int> > leftChain, rightChain;
//     std::list<std::pair<int, int> >::iterator it = mainChain.begin();
//     for (size_t i = 0; i < mainChain.size() / 2; ++i) {
//         leftChain.push_back(*it);
//         ++it;
//     }
//     for (; it != mainChain.end(); ++it) {
//         rightChain.push_back(*it);
//     }
// 
//     // 재귀적으로 정렬
//     mergeSortList(leftChain);
//     mergeSortList(rightChain);
// 
//     // 병합 단계
//     std::list<std::pair<int, int> >::iterator leftIt = leftChain.begin();
//     std::list<std::pair<int, int> >::iterator rightIt = rightChain.begin();
// 
//     mainChain.clear();
//     while (leftIt != leftChain.end() && rightIt != rightChain.end()) {
//         if (leftIt->first <= rightIt->first) {
//             mainChain.push_back(*leftIt);
//             ++leftIt;
//         } else {
//             mainChain.push_back(*rightIt);
//             ++rightIt;
//         }
//     }
//     while (leftIt != leftChain.end()) {
//         mainChain.push_back(*leftIt);
//         ++leftIt;
//     }
//     while (rightIt != rightChain.end()) {
//         mainChain.push_back(*rightIt);
//         ++rightIt;
//     }
// }
// 
// 
// std::list<int> mergeInsertionList(std::list<int> data_list, std::list<std::pair<int, int> > mainChain) {
//   mergeSortList(mainChain);
//   std::list<int> sorted_list;
//   
//   for (std::list<std::pair<int, int> >::iterator i = mainChain.begin(); i != mainChain.end();i++) {
//     sorted_list.push_back(i->first);
//   }
//   sorted_list.push_front(mainChain.begin()->second);
//   
//   size_t idx = 1;
//   for (size_t i = 1; i < mainChain.size(); i++) {
// 	size_t beforeJacobNum = 1;
// 	size_t k = getJacobsthalNum(i, &beforeJacobNum) - 1;
// 	if (k > mainChain.size() - 1) // JacobNum보다 사이즈가 작으면 사이즈부터 시작 ex) JacobNum = 11, mainChain.size = 8 -> 8부터 시작
// 		k = mainChain.size() - 1;
// 	i = k;
// 	for (; k >= beforeJacobNum; k--)
// 	{
// 		std::list<std::pair<int, int> >::iterator it = mainChain.begin();
// 		std::list<int>::iterator right = sorted_list.begin();
// 		for (size_t i = 0; i < k; i++){
// 			it++;
// 			right++;
// 		}
// 		for (size_t i = 0; i < idx; i++)
// 			right++;
// 		binarySearchList(sorted_list, static_cast<int>(it->second), sorted_list.begin(), right);
// 		idx++;
// 	}
//   }
//   if (data_list.size() % 2 == 1) {
//     binarySearchList(sorted_list, static_cast<int>(data_list.back()), sorted_list.begin(), sorted_list.end());
//   }
//   return sorted_list;
// }
// 
// void PmergeMe::sortList(std::list<int> &sorted_list) {
//   std::list<std::pair<int, int> > mainChain;
// 
// 	for (std::list<int>::iterator i = data_list.begin(); i != data_list.end();){
// 		std::list<int>::iterator next = i;
//         ++next;
//         if (next == data_list.end())
//             break;
//         if (*i < *next)
//             mainChain.push_back(std::make_pair(*next, *i));
//         else
//             mainChain.push_back(std::make_pair(*i, *next));
//         i = ++next;
// 	}
// 	sorted_list = mergeInsertionList(data_list, mainChain);
// }

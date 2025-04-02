#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int len)
{
	clock_t	vec_start, vec_finish, list_start, list_finish;
	std::vector<int> sorted_vector;
	std::list<int> sorted_list;

	for (int i=1;i<len;i++)
		getData(av[i]);
	alreadySorted(); // 이미 정렬되있다면 에러

	vec_start = clock();
	sortVec(sorted_vector);
	vec_finish = clock();

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

void mergeSortVec(std::vector< std::pair<int, int> >& pairs, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSortVec(pairs, left, mid);
    mergeSortVec(pairs, mid + 1, right);
    std::vector< std::pair<int, int> > temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
    	// cnt++;
        if (pairs[i].first < pairs[j].first)
            temp.push_back(pairs[i++]);
        else
            temp.push_back(pairs[j++]);
    }
    while (i <= mid)
        temp.push_back(pairs[i++]);
    while (j <= right)
        temp.push_back(pairs[j++]);
    
    for (int k = left; k <= right; k++) {
        pairs[k] = temp[k - left];
    }
}

size_t getJacobsthalNum(size_t i, size_t *beforeJacobNum) {
    int t = 1;
    size_t JacobNum;
    *beforeJacobNum = 0;
    while (true) {
        JacobNum = (static_cast<size_t>(pow(2, t)) - static_cast<size_t>(pow(-1, t))) / 3;
        if (i < JacobNum)
            break;
        *beforeJacobNum = JacobNum;
        t++;
    }
    return JacobNum;
}

std::vector<size_t> saveJacobsthalNum(size_t n) {
    std::vector<size_t> order;
    size_t start = 0;
    while (start < n) {
        size_t beforeJacob = 0;
        size_t J = getJacobsthalNum(start, &beforeJacob);
        size_t groupSize = J - beforeJacob;
        if (start + groupSize > n)
            groupSize = n - start;
        for (size_t i = start + groupSize; i > start; i--) {
            order.push_back(i - 1);
        }
        start += groupSize;
    }
    return order;
}

int BinarySearchVec(const std::vector<int>& sorted, int value, int left, int right) {
    if (left > right)
        return left;
    int mid = left + (right - left) / 2;
	// cnt++;
    if (value < sorted[mid])
        return BinarySearchVec(sorted, value, left, mid - 1);
    else
        return BinarySearchVec(sorted, value, mid + 1, right);
}

std::vector<int> InsertVec(const std::vector<int>& sorted, int value) {
    int index = BinarySearchVec(sorted, value, 0, static_cast<int>(sorted.size()) - 1);
    std::vector<int> result(sorted);
    result.insert(result.begin() + index, value);
    return result;
}

std::vector<int> fordJohnsonVec(const std::vector<int>& data) {
    
    std::vector< std::pair<int, int> > mainChain; // 쌍 생성 (A: 더 큰 값, B: 더 작은 값)
    size_t n = data.size();
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (data[i] < data[i + 1])
            mainChain.push_back(std::make_pair(data[i + 1], data[i]));
        else
            mainChain.push_back(std::make_pair(data[i], data[i + 1]));
    }

    int unpaired = 0;
    if (n % 2 == 1)
        unpaired = data[n - 1];
    
    mergeSortVec(mainChain, 0, static_cast<int>(mainChain.size()) - 1);  // 쌍들을 merge sort로 정렬
    
    // 큰값들만 모아서 재귀 정렬
    std::vector<int> sortedA;
    for (size_t i = 0; i < mainChain.size(); i++) {
        sortedA.push_back(mainChain[i].first);
    }
    
	sortedA.insert(sortedA.begin(), mainChain[0].second); // B[0]은 확정으로 첫자리    

    std::vector<int> B;
    for (size_t i = 0; i < mainChain.size(); i++) {
        B.push_back(mainChain[i].second);
    }
    
    // Jacobsthal 기반 삽입 순서로 삽입
    if (B.size() > 0) {
        std::vector<size_t> insertionOrder = saveJacobsthalNum(B.size());
        for (size_t i = 1; i < insertionOrder.size(); i++) {
            size_t idx = insertionOrder[i];
            sortedA = InsertVec(sortedA, B[idx]);
        }
    }
    
    // 홀수개인 경우, 남은 unpaired 원소 삽입
    if (unpaired != 0)
        sortedA = InsertVec(sortedA, unpaired);
    
    return sortedA;
}

void PmergeMe::sortVec(std::vector<int> &sorted_vector) {
	sorted_vector = fordJohnsonVec(data_vec);
}


std::list< std::pair<int,int> > mergeSortList(std::list< std::pair<int,int> > L) {
    if (L.size() <= 1)
        return L;
    
    std::list< std::pair<int,int> > left, right;
    std::list< std::pair<int,int> >::iterator it = L.begin();
    size_t mid = L.size() / 2;
    for (size_t i = 0; i < mid; i++, ++it)
        left.push_back(*it);
    for (; it != L.end(); ++it)
        right.push_back(*it);
    
    left = mergeSortList(left);
    right = mergeSortList(right);
    
    std::list< std::pair<int,int> > result;
    while (!left.empty() && !right.empty()) {
        if (left.front().first < right.front().first) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
    }
    return result;
}

std::list<size_t> saveJacobsthalNumList(size_t n) {
    std::list<size_t> order;
    size_t start = 0;
    while (start < n) {
        size_t beforeJacob = 0;
        size_t J = getJacobsthalNum(start, &beforeJacob);
        size_t groupSize = J - beforeJacob;
        if (start + groupSize > n)
            groupSize = n - start;
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
    if (n <= 0)
        return begin;
    int midIndex = n / 2;
    std::list<int>::iterator mid = begin;
    for (int i = 0; i < midIndex; i++) {
        ++mid;
    }
    if (value < *mid)
        return listBinarySearchHelper(sorted, value, begin, mid, midIndex);
    else {
        std::list<int>::iterator next = mid;
        ++next;
        return listBinarySearchHelper(sorted, value, next, end, n - midIndex - 1);
    }
}

std::list<int>::iterator listBinarySearch(std::list<int>& sorted, int value) {
    int n = static_cast<int>(sorted.size());
    return listBinarySearchHelper(sorted, value, sorted.begin(), sorted.end(), n);
}

void recursiveInsertList(std::list<int>& sorted, int value) {
    std::list<int>::iterator pos = listBinarySearch(sorted, value);
    sorted.insert(pos, value);
}

std::list<int> fordJohnsonList(const std::list<int>& data) {
    std::list< std::pair<int,int> > pairs;
    std::list<int>::const_iterator it = data.begin();
    while (it != data.end()) {
        int first = *it;
        ++it;
        if (it != data.end()) {
            int second = *it;
            ++it;
            if (first < second)
                pairs.push_back(std::make_pair(second, first));
            else
                pairs.push_back(std::make_pair(first, second));
        } else {
            break;
        }
    }
    int unpaired = 0;
    if (data.size() % 2 == 1) {
        std::list<int>::const_iterator last = data.end();
        --last;
        unpaired = *last;
    }
    
    pairs = mergeSortList(pairs);
    std::list<int> sortedA;
    for (std::list< std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it){
        sortedA.push_back(it->first);}
	sortedA.push_front(pairs.front().second);
    
    std::list<int> pending;
    for (std::list< std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
            pending.push_back(it->second);
    }
    
    // pending 요소들을 Jacobsthal 기반 삽입
    if (!pending.empty()) {
        std::list<size_t> insertionOrder = saveJacobsthalNumList(pending.size());
        std::list<size_t>::iterator insertionIt = insertionOrder.begin();
        ++insertionIt;
        for (; insertionIt != insertionOrder.end(); ++insertionIt) {
            size_t idx = *insertionIt;
            std::list<int>::iterator pendingIt = pending.begin();
            std::advance(pendingIt, idx);
            recursiveInsertList(sortedA, *pendingIt);
        }
    }
    
    if (data.size() % 2 == 1)
        recursiveInsertList(sortedA, unpaired);
    
    return sortedA;
}

void	PmergeMe::sortList(std::list<int> &sort_list){
	sort_list = fordJohnsonList(data_list);
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

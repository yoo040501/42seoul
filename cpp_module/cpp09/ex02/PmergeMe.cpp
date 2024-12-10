#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int len)
{
	clock_t	vec_start, vec_finish, deq_start, deq_finish;
	std::vector<int> sorted_vector;
	std::deque<int> sorted_deque;

	for (int i=1;i<len;i++)
		getData(av[i]);
	alreadySorted(); // 이미 정렬되있다면 에러

	vec_start = clock();
	sortVec(sorted_vector);
	vec_finish = clock();

	deq_start = clock();
	sortDeq(sorted_deque);
	deq_finish = clock();

	printElement(sorted_vector, sorted_deque);
	printTime(vec_start, vec_finish, deq_start, deq_finish);
}

PmergeMe::~PmergeMe(){
}

void	PmergeMe::printTime(clock_t vec_start, clock_t vec_finish, clock_t deq_start, clock_t deq_finish)
{
	std::cout << "Time to process a range of " << data.size() << " elements with std::vector : "
				<< static_cast<double>(vec_finish - vec_start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	std::cout << "Time to process a range of " << data_deq.size() << " elements with std::deque : "
			<< static_cast<double>(deq_finish - deq_start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}

void	PmergeMe::alreadySorted(){
	for (size_t i = 1; i < data.size(); ++i) {
        if (data[i - 1] > data[i]) return;
    }
	throw std::invalid_argument("\033[0;31mAlready sorted...\033[0;0m");
}

void	PmergeMe::printElement(std::vector<int> sorted_vector, std::deque<int> sorted_deque)
{
	std::cout << "Before: ";
	for (size_t i=0;i < data.size();i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;

	std::vector<int> tmp = data;
	sort(tmp.begin(), tmp.end());
	for (size_t i=0;i<tmp.size();i++){
		if (tmp[i] != sorted_vector[i])
			throw std::invalid_argument("\033[0;31msort fail!\033[0;0m");
	}

	std::deque<int> tmp_deq = data_deq;
	sort(tmp_deq.begin(), tmp_deq.end());
	for (size_t i=0;i<tmp_deq.size();i++){
		if (tmp_deq[i] != sorted_deque[i])
			throw std::invalid_argument("\033[0;31msort fail!\033[0;0m");
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
		data.push_back(static_cast<int>(number));
		data_deq.push_back(static_cast<int>(number));
	}
}

size_t	getJacobsthalNum(size_t i, size_t *beforeJacobNum)
{
	int	t = 2;
	size_t	JacobNum;
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

void binarySearchVec(std::vector<int> &sorted, int b, int left, int right) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (sorted[mid] <= b){
      left = mid + 1;}
	else if (sorted[mid] > b){
      right = mid - 1;}
  }
  sorted.insert(sorted.begin() + left, b);
}

void mergeSortVec(std::vector<std::pair<int, int> > &mainChain, int left, int right) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
    // 왼쪽 및 오른쪽 반을 재귀 정렬
    mergeSortVec(mainChain, left, mid);
    mergeSortVec(mainChain, mid + 1, right);

    // 병합 단계
    int i = left;
    int j = mid + 1;
    int k = 0;
    std::vector<std::pair<int, int> > temp(right - left + 1); // 정렬될 공간 우선 확보 (idx로 하기 위해서)

    // 왼쪽과 오른쪽 리스트를 병합
    while (i <= mid && j <= right) {
        if (mainChain[i].first <= mainChain[j].first)
            temp[k++] = mainChain[i++];
		else {
            temp[k++] = mainChain[j++];}
    }
    // 왼쪽 리스트의 남은 요소 복사
    while (i <= mid) {
        temp[k++] = mainChain[i++];
    }
    // 오른쪽 리스트의 남은 요소 복사
    while (j <= right) {
        temp[k++] = mainChain[j++];
    }
    // 병합된 결과를 원래 리스트에 복사
    for (size_t l = 0; l < temp.size(); ++l) {
        mainChain[left + l] = temp[l];
    }
}

std::vector<int> mergeInsertionVector(std::vector<int> data, std::vector<std::pair<int, int> > mainChain) {
  mergeSortVec(mainChain, 0, mainChain.size() - 1);
  std::vector<int> sorted_vector;
  
  for (size_t i = 0; i < mainChain.size(); i++) {
    sorted_vector.push_back(mainChain[i].first);
  }
  sorted_vector.insert(sorted_vector.begin(), mainChain[0].second);
	size_t idx = 1;
  
  for (size_t i = 1; i < mainChain.size(); i++) {       
	if (mainChain[i].first == 0)
		continue;
	
	size_t beforeJacobNum = 1;
	size_t k = getJacobsthalNum(i, &beforeJacobNum) - 1;
	if (k >= mainChain.size()) // JacobNum보다 사이즈가 작으면 사이즈부터 시작 ex) JacobNum = 11, mainChain.size = 8 -> 8부터 시작
		k = mainChain.size() - 1;
	for (; k >= beforeJacobNum; k--)
	{
		// mainChain에서 a값 위치 찾아서 이진탐색할 b 오른쪽 범위 설정 (sorted : 1 3 4 5 6 7 10) 6까지 이진탐색을 하면 됨
		size_t right = k + idx;
		binarySearchVec(sorted_vector, static_cast<int>(mainChain[k].second), 0, static_cast<int>(right));
		mainChain[k].first = 0;
		idx++;
	}
  }
  if (data.size() % 2 == 1) {
    binarySearchVec(sorted_vector, data[data.size() - 1], 0, static_cast<int>(sorted_vector.size()) - 1);
  }
  return sorted_vector;
}

void PmergeMe::sortVec(std::vector<int> &sorted_vector) {
  std::vector<std::pair<int, int> > mainChain;

	for (size_t i = 0; i + 1 < data.size(); i += 2){
		if (data[i] < data[i + 1])
			mainChain.push_back(std::make_pair(data[i + 1], data[i]));
		else
			mainChain.push_back(std::make_pair(data[i], data[i + 1]));
	}
	sorted_vector = mergeInsertionVector(data, mainChain);
}

void binarySearchDeq(std::deque<int> &sorted, int b, int left, int right) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (sorted[mid] <= b){
      left = mid + 1;}
	else if (sorted[mid] > b){
      right = mid - 1;}
  }
  sorted.insert(sorted.begin() + left, b);
}

void mergeSortDeq(std::deque<std::pair<int, int> > &mainChain, int left, int right) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
    // 왼쪽 및 오른쪽 반을 재귀적으로 정렬
    mergeSortDeq(mainChain, left, mid);
    mergeSortDeq(mainChain, mid + 1, right);

    // 병합 단계
    int i = left;
    int j = mid + 1;
    int k = 0;
    std::deque<std::pair<int, int> > temp(right - left + 1);

    // 왼쪽과 오른쪽 리스트를 병합
    while (i <= mid && j <= right) {
        if (mainChain[i].first <= mainChain[j].first)
            temp[k++] = mainChain[i++];
		else {
            temp[k++] = mainChain[j++];}
    }
    // 왼쪽 리스트의 남은 요소 복사
    while (i <= mid) {
        temp[k++] = mainChain[i++];
    }
    // 오른쪽 리스트의 남은 요소 복사
    while (j <= right) {
        temp[k++] = mainChain[j++];
    }
    // 병합된 결과를 원래 리스트에 복사
    for (size_t l = 0; l < temp.size(); ++l) {
        mainChain[left + l] = temp[l];
    }
}


std::deque<int> mergeInsertionDeque(std::deque<int> data, std::deque<std::pair<int, int> > mainChain) {
  mergeSortDeq(mainChain, 0, mainChain.size() - 1);
  std::deque<int> sorted_deque;
  
  for (size_t i = 0; i < mainChain.size(); i++) {
    sorted_deque.push_back(mainChain[i].first);
  }
  sorted_deque.insert(sorted_deque.begin(), mainChain[0].second);
  
  size_t idx = 1;
  for (size_t i = 1; i < mainChain.size(); i++) {
	if (mainChain[i].first == 0)
		continue;
	size_t beforeJacobNum = 1;
	size_t k = getJacobsthalNum(i, &beforeJacobNum) - 1;
	if (k > mainChain.size() - 1) // JacobNum보다 사이즈가 작으면 사이즈부터 시작 ex) JacobNum = 11, mainChain.size = 8 -> 8부터 시작
		k = mainChain.size() - 1;
	
	for (; k >= beforeJacobNum; k--)
	{
		size_t right = k + idx;
		// size_t right = std::find(sorted_vector.begin(), sorted_vector.end(), mainChain[k].first) - sorted_vector.begin();
		binarySearchDeq(sorted_deque, static_cast<int>(mainChain[k].second), 0, static_cast<int>(right) - 1);
		mainChain[k].first = 0;
		idx++;
	}
  }
  if (data.size() % 2 == 1) {
    binarySearchDeq(sorted_deque, data[data.size() - 1], 0, static_cast<int>(sorted_deque.size()) - 1);
  }
  return sorted_deque;
}

void PmergeMe::sortDeq(std::deque<int> &sorted_deq) {
  std::deque<std::pair<int, int> > mainChain;

	for (size_t i = 0; i + 1 < data_deq.size(); i += 2){
		if (data_deq[i] < data_deq[i + 1])
			mainChain.push_back(std::make_pair(data_deq[i + 1], data_deq[i]));
		else
			mainChain.push_back(std::make_pair(data_deq[i], data_deq[i + 1]));
	}
	sorted_deq = mergeInsertionDeque(data_deq, mainChain);
}

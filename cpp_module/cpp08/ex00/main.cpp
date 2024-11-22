#include "easyfind.hpp"
#include <vector>
#include <queue>
#include <deque>
#include <list>

int main()
{
	std::vector<int> vec;
	for (int i=0;i<5;i++)
		vec.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "찾은 값: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::list<int> lt;
    lt.push_back(5);
    lt.push_back(50);
    lt.push_back(4);
    lt.push_back(12);
    lt.push_back(1);

	try {
        std::list<int>::iterator it = easyfind(lt, 1);
        std::cout << "찾은 값: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}

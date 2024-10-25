#include "easyfind.hpp"
#include <vector>
#include <queue>
#include <deque>
#include <list>

int main()
{
	std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "찾은 값: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::list<int> lt;
	lt.push_back(5);
	lt.push_back(50);
	lt.push_back(3);
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(4);

	 try {
        std::list<int>::iterator it = easyfind(lt, 1);
        std::cout << "찾은 값: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}

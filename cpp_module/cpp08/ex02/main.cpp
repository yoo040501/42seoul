#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "----------------------------------------\n";
		std::cout << "		MutantStack" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack);
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
		while (rit != rite) {
			std::cout << *rit << std::endl;
		++rit; }
	}
	std::cout << "----------------------------------------\n";
	std::cout << "		list" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	{
		std::list<int> l;
		l.push_back(5);
		l.push_back(17);
		l.pop_back();
		std::cout << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::list<int>::reverse_iterator rit = l.rbegin();
		std::list<int>::reverse_iterator rite = l.rend();
		++rit;
		--rit;
		while (rit != rite) {
			std::cout << *rit << std::endl;
		++rit; }
	}
	return 0;
}

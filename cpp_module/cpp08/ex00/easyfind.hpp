#pragma once

#include <iostream>
#include <cstring>

class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Element not found in container";
    }
};

template <typename T>
typename T::iterator	easyfind(T& container, int value){
		typename T::iterator n = std::find(container.begin(), container.end(), value);
		if (n == container.end())
			throw NotFoundException();
		return n;
}

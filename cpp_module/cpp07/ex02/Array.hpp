#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		std::size_t len;
		T *arr;
	public:
		Array(void);
		Array(std::size_t n);
		Array(const Array& obj);
		Array& operator=(const Array& obj);
		~Array();

		std::size_t size(void) const;
		T& operator[] (std::size_t i);
		const T& operator[] (std::size_t i) const;
};

#include "Array.tpp"
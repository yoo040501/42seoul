#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : len(0), arr(NULL) {}

template <typename T>
Array<T>::Array(std::size_t n) : len(n), arr(new T[n]()) {}

template <typename T>
Array<T>::Array(const Array<T>& copy) {
	len = copy.len;
	arr = new T[copy.len];
	for (size_t i = 0; i < len; i++)
		arr[i] = copy.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const &other) {
	if (*this != other)
	{
		this->len = other.len;
		delete[] this->arr;
		this->arr = new T[len];
		for (size_t i = 0; i < len; i++)
			arr[i] = other.arr[i];
	}
  return *this;
}

template <typename T>
Array<T>::~Array() {
  delete[] arr;
}

template <typename T>
const T& Array<T>::operator[](size_t i) const {
  if (i < 0 || i >= this->len)
    throw std::out_of_range("Error:index out of range");
  return arr[i];
}

template <typename T>
T& Array<T>::operator[](size_t i) {
  if (i < 0 || i >= this->len)
    throw std::out_of_range("Error:Index out of range");
  return arr[i];
}

template <typename T>
size_t Array<T>::size() const {
  return this->len;
}

template <typename T>
bool Array<T>::operator!=(const Array<T>& other) const {
    if (this->len != other.len) {
        return true;
    }
    for (size_t i = 0; i < this->len; i++) {
        if (this->arr[i] != other.arr[i]) {
            return true;
        }
    }
    return false;
}

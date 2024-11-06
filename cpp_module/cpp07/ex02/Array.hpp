#pragma once

#include <iostream>

// Develop a class template Array that contains elements of type T and that implements the following behavior and functions:
// • Construction with no parameter: Creates an empty array.
// • Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
// • Construction by copy and assignment operator. 
//   In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory.
//   Preventive allocation (al- locating memory in advance) is forbidden. Your program must never access non- allocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameter and musn’t modify the current instance.
// As usual, ensure everything works as expected and turn in a main.cpp file that con- tains your tests.

// 이 과제는 T 타입의 요소를 포함하는 Array라는 클래스 템플릿을 개발하라는 것입니다. 이 클래스는 다음과 같은 동작과 함수를 구현해야 합니다:
// 생성자:
// 매개변수 없는 생성자: 빈 배열을 생성합니다.
// unsigned int n을 매개변수로 받는 생성자: n개의 요소를 가진 배열을 생성하고, 기본값으로 초기화합니다.
// 팁: int * a = new int();를 컴파일한 후 *a를 출력해보세요.
// 복사 생성자와 대입 연산자:
// 복사 후 원본 배열이나 복사본을 수정해도 다른 배열에 영향을 주지 않아야 합니다.
// 메모리 할당:
// 메모리 할당에는 반드시 operator new[]를 사용해야 합니다.
// 예방적 할당(미리 메모리를 할당하는 것)은 금지됩니다. 프로그램은 절대 할당되지 않은 메모리에 접근해서는 안 됩니다.
// 요소 접근:
// 요소는 첨자 연산자 []를 통해 접근할 수 있어야 합니다.
// [] 연산자로 요소에 접근할 때, 인덱스가 범위를 벗어나면 std::exception을 throw해야 합니다.
// size() 함수:
// 배열의 요소 수를 반환하는 size() 멤버 함수를 구현해야 합니다.
// 이 함수는 매개변수를 받지 않으며, 현재 인스턴스를 수정해서는 안 됩니다.
// 마지막으로, 모든 기능이 예상대로 작동하는지 확인하고, 테스트를 포함한 main.cpp 파일을 제출하라고 요구하고 있습니다.

template <typename T>
template <typename T>
class Array {
 private:
	std::size_t len;
	T *array;
 public:
	Array(void);
	Array(std::size_t n);
	Array(const Array& obj);
	Array& operator=(const Array& obj);
	~Array(void);
	std::size_t size(void) const;
	T& operator[] (std::size_t i);
	const T& operator[] (std::size_t i) const;
};

# include "Array.tpp"

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(uint size) : _size(size), _data(new T[size]()) {}

template <typename T>
Array<T>::Array(const Array<T>& other)
    : _size(other._size), _data(new T[other._size]) {
  for (size_t i = 0; i < _size; i++)
    _data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array() {
  delete[] _data;
}

// Operators
template <typename T>
static void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
  Array tmp(other);
  swap(_size, tmp._size);
  swap(_data, tmp._data);
  return *this;
}

template <typename T>
inline bool Array<T>::is_valid_index(size_t index) const {
  return (0 <= index && index < _size);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
  if (not is_valid_index(index))
    throw std::out_of_range("(value) Index out of range");
  return _data[index];
}

template <typename T>
T& Array<T>::operator[](size_t index) {
  if (not is_valid_index(index))
    throw std::out_of_range("(reference) Index out of range");
  return _data[index];
}

template <typename T>
size_t Array<T>::size() const {
  return _size;
}

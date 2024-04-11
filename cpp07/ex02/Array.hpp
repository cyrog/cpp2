#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class	Array {
	private:
		T				*_arr;
		unsigned int	_size;
	
	public:
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(Array const &src);
		~Array<T>();

		Array<T>	&operator=(Array const &rhs);

		T			&operator[](unsigned int const i);

		unsigned int	size() const;

		class	IndexOutOfBounds : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Out of bounds");
				}
		};
};

template <typename T>
Array<T>::Array() {
	_arr = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	_arr = new T[_size];
}

template <typename T>
Array<T>::Array(Array const &src) {
	this->_size = src._size;
	this->_arr = new T(src._size);
	for (unsigned int i = 0; i < src._size; i++) {
		this->_arr[i] = src._arr[i];
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &rhs) {
	if (this->_arr)
		delete[] this->_arr;
	this->_size = rhs._size;
	this->_arr = new T(this->_size);
	for (unsigned int i; i < rhs._size; i++) {
		this->_arr[i] = rhs._arr[i];
	}
	return *this;
}

template <typename T>
T	&Array<T>::operator[](unsigned int const i) {
	if (i < 0 || i >= this->_size)
		throw IndexOutOfBounds();
	return (this->_arr[i]);

}

template <typename T>
Array<T>::~Array() {
	if (this->_arr)
		delete[] this->_arr;
}

template <typename T>
unsigned int	Array<T>::size() const {
	return this->_size;
}

#endif

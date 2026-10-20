/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 18:21:32 by kuyu              #+#    #+#             */
/*   Updated: 2026/10/20 23:57:07 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(new T[other._size]()), _size(other._size)
{
	try
	{
		for (std::size_t i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	catch (...)
	{
		delete[] this->_array;
		throw;
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other)
	{
		Array<T> copy(other);
		T *old_array = this->_array;
		unsigned int old_size = this->_size;
		this->_array = copy._array;
		this->_size = copy._size;
		copy._array = old_array;
		copy._size = old_size;
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return this->_array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return this->_array[index];
}

template <typename T>
unsigned int	Array<T>::size() const {
	return this->_size;
}

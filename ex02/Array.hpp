/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kunlei <kunlei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 21:58:33 by kunlei            #+#    #+#             */
/*   Updated: 2026/10/19 08:42:47 by kunlei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	public:
		Array();		// Constructor with no parameter, creates an empty array
		Array(unsigned int n);	// Constructor with a parameter, creates an array of size n, initialized with default values
		Array(const Array<T> &other);
		~Array();		// Destructor, deallocates the memory used by the array

		Array<T> &operator=(const Array<T> &other);

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int	size() const;

	private:
		T	*_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
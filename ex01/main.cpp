/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kunlei <kunlei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:37:44 by kunlei            #+#    #+#             */
/*   Updated: 2026/10/18 18:37:04 by kunlei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

// Read-only function: accepts const reference
template <typename T>
void	print(const T &string) {
	std::cout << string << " ";
}

// Modifying function: accepts non-const reference
template <typename T>
void	increment(T &value) {
	value++;
}

//Modifying function for strings
void	appendText(std::string & str) {
	str += "_modified";
}

int	main()
{
    // Test 1: int array with const reference
    std::cout << "=== Test 1: read int array ===" << std::endl;
    int arr1[] = {1, 2, 3, 4, 5};
    iter(arr1, 5, print<int>);
    std::cout << std::endl;

    // Test 2: modify int array
    std::cout << "\n=== Test 2: modify int array ===" << std::endl;
    iter(arr1, 5, increment<int>);
    iter(arr1, 5, print<int>);
    std::cout << std::endl;

    // Test 3: const int array
    std::cout << "\n=== Test 3: const int array ===" << std::endl;
    const int arr2[] = {10, 20, 30};
    iter(arr2, 3, print<int>);
    std::cout << std::endl;

    // Test 4: char array
    std::cout << "\n=== Test 4: char array ===" << std::endl;
    char arr3[] = {'a', 'b', 'c'};
    iter(arr3, 3, print<char>);
    std::cout << std::endl;

    // Test 5: std::string array
    std::cout << "\n=== Test 5: string array ===" << std::endl;
    std::string arr4[] = {"hello", "world", "cpp07"};
    iter(arr4, 3, print<std::string>);
    std::cout << std::endl;

    // Test 6: modify string array
    std::cout << "\n=== Test 6: modify string array ===" << std::endl;
    iter(arr4, 3, appendText);
    iter(arr4, 3, print<std::string>);
    std::cout << std::endl;

    // Test 7: const string array
    std::cout << "\n=== Test 7: const string array ===" << std::endl;
    const std::string arr5[] = {"one", "two", "three"};
    iter(arr5, 3, print<std::string>);
    std::cout << std::endl;

    // Test 8: empty array (length = 0)
    std::cout << "\n=== Test 8: zero length ===" << std::endl;
    iter(arr1, 0, print<int>);
    std::cout << "No elements processed." << std::endl;

    return 0;
}

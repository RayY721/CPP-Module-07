/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kunlei <kunlei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 02:13:17 by kunlei            #+#    #+#             */
/*   Updated: 2026/10/18 10:11:19 by kunlei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const&	min(T const& a, T const& b){
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T const&	max(T const& a, T const& b){
	if (a > b)
		return a;
	else
		return b;
}

#endif
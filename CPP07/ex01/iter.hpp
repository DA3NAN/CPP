/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:51 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/10 19:13:17 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *arr, int len, void (*f)(T &)) {
	for (int i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template <typename T>
void print(T &a) {
	std::cout << a << std::endl;
}

template <typename T>
void increment(T &a) {
	a++;
}

#endif

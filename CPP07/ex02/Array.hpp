/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:23:01 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/12 15:30:51 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
	private:
		T *_arr;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & src);
		~Array();
		Array & operator=(Array const & src);
		T & operator[](unsigned int index);
		unsigned int size() const;
		class OutOfLimits : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif

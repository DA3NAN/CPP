/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:59:45 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/14 15:36:17 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {}
		MutantStack(MutantStack const & src) {
			*this = src;
		}
		MutantStack & operator=(MutantStack const & src) {
			if (this != &src)
				std::stack<T>::operator=(src);
			return *this;
		}
		~MutantStack() {}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() {
			return MutantStack<T>::c.begin();
		}
		iterator end() {
			return MutantStack<T>::c.end();
		}

		const_iterator begin() const {
			return MutantStack<T>::c.begin();
		}
		const_iterator end() const {
			return MutantStack<T>::c.end();
		}

		reverse_iterator rbegin() {
			return MutantStack<T>::c.rbegin();
		}
		reverse_iterator rend() {
			return MutantStack<T>::c.rend();
		}

		const_reverse_iterator rbegin() const {
			return MutantStack<T>::c.rbegin();
		}
		const_reverse_iterator rend() const {
			return MutantStack<T>::c.rend();
		}
};

#endif

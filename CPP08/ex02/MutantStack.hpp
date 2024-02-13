/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:59:45 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/13 20:01:25 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	private:
		std::stack<T> _stack;
	public:
		MutantStack() : _stack() {}
		MutantStack(MutantStack const & stack) {
			*this = stack;
		}
		MutantStack & operator=(MutantStack const & stack) {
			if (this != &stack) {
				if (_stack.size() > 0)
					_stack.clear();
				if (stack._stack.size() > 0) {
					std::stack<T> tmp = stack._stack;
					while (!tmp.empty()) {
						_stack.push(tmp.top());
						tmp.pop();
					}
				}
			}
			return *this;
		}
		~MutantStack() {
			if (_stack.size() > 0)
				_stack.clear();
		}
		void push(T value) {
			_stack.push(value);
		}
		void pop() {
			_stack.pop();
		}
		T & top() {
			return _stack.top();
		}
		size_t size() {
			return _stack.size();
		}
		bool empty() {
			return _stack.empty();
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {
			return _stack.c.begin();
		}
		iterator end() {
			return _stack.c.end();
		}
};

#endif

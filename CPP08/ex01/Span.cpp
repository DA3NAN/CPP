/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:43:44 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/13 19:54:11 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const & span) {
	*this = span;
}

Span & Span::operator=(Span const & span) {
    if (this != &span) {
		if (_v.size() > 0)
			_v.clear();

        if (_n != span._n) {
            _n = span._n;
        }

		if (span._v.size() > 0)
			for (size_t i = 0; i < _n; ++i) {
				_v.push_back(span._v[i]);
			}
    }
    return *this;
}

Span::~Span() {
	if (_v.size() > 0)
		_v.clear();
}

void Span::addNumber(int n) {
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw std::runtime_error("Cannot add more numbers to the container");
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_v.size() + std::distance(begin, end) <= _n)
		_v.insert(_v.end(), begin, end);
	else
		throw std::runtime_error("Cannot add All the numbers to the container");
}

int Span::shortestSpan() {
	size_t size = _v.size();
	if (size < 2)
		throw std::runtime_error("The container has less than 2 elements");

	std::sort(_v.begin(), _v.end());
	int min = _v[1] - _v[0];

	for (size_t i = 2; i < size; ++i) {
		if (_v[i] - _v[i - 1] < min)
			min = _v[i] - _v[i - 1];
	}
	return min;
}

int Span::longestSpan() {
	if (_v.size() < 2)
		throw std::runtime_error("The container has less than 2 elements");
	std::sort(_v.begin(), _v.end());
	return _v[_v.size() - 1] - _v[0];
}

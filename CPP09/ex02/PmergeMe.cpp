/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:44:18 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/17 19:51:04 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string const &input) {
	std::stringstream ss(input);
	std::string token;
	while (std::getline(ss, token, ' ')) {
		_v.push_back(stringToInt(token));
		_l.push_back(stringToInt(token));
	}
}

PmergeMe::PmergeMe(PmergeMe const &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		_v = other._v;
		_l = other._l;
	}
	return *this;
}

void PmergeMe::SortVector() {
	std::sort(_v.begin(), _v.end());
}

void PmergeMe::SortList() {
	_l.sort();
}

void PmergeMe::printVector() const {
	for (std::vector<int>::const_iterator it = _v.begin(); it != _v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList() const {
	for (std::list<int>::const_iterator it = _l.begin(); it != _l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int stringToInt(const std::string& str) {
    char* endptr;
    long int result = strtol(str.c_str(), &endptr, 10);

    if (result < INT_MIN || result > INT_MAX) {
        throw std::runtime_error("Number is out of int range");
    }

    return static_cast<int>(result);
}

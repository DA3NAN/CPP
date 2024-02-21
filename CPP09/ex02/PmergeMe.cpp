/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:44:18 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/21 16:04:49 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) {
	_start = clock();
	clock_t end;

	for (int i = 1; i < ac; i++) {
		std::string argument(av[i]);
		size_t start = 0;
		size_t end = argument.size();

		// Skip leading whitespaces
		while (start < end && std::isspace(argument[start]))
			start++;

		// Skip trailing whitespaces
		while (end > start && std::isspace(argument[end - 1]))
			end--;

		std::string token;
		std::stringstream ss(argument.substr(start, end - start));
		while (ss >> token) {
			_v.push_back(stringToInt(token));
			_d.push_back(stringToInt(token));
		}
	}

	if (_v.empty()) {
		throw std::runtime_error("No data to process");
	}

	end = clock();
	_dataTime = static_cast<double>(end - _start) / CLOCKS_PER_SEC * 1000;
}

PmergeMe::PmergeMe(PmergeMe const &other) {
	_start = clock();
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		_v = other._v;
		_d = other._d;
	}
	return *this;
}

void PmergeMe::SortVector() {
	_start = clock();

	std::vector<std::pair<int, int> > v_pairs;
	std::vector<int> mainChain, pend, newPend;
	std::vector<int> pendIndexes, jacobStal, combination;
	int struggler = -1;
	clock_t end;

	if (_v.size() % 2 != 0) {
		struggler = _v.back();
		_v.pop_back();
	}

	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it += 2) {
		v_pairs.push_back(std::make_pair(*it, *(it + 1)));
	}

	sortThePairs(v_pairs);
	sortByFirst(v_pairs);
	createMainChainAndPend(v_pairs, mainChain, pend);
	indexPend(pend, pendIndexes);
	createJacobStal(pendIndexes, jacobStal);
	combination = creatIndexCombinations(pendIndexes, jacobStal);
	newPend = createNewPend(pend, combination);
	binarySort(mainChain, newPend, struggler);

	end = clock();
	_vectorTime = (double)(end - _start) / CLOCKS_PER_SEC * 1000000.0;
}

void PmergeMe::SortDeque() {
	_start = clock();

    std::deque<std::pair<int, int> > d_pairs;
    std::deque<int> mainChain, pend, newPend;
    std::deque<int> pendIndexes, jacobStal, combination;
    int struggler = -1;
    clock_t end;

    if (_d.size() % 2 != 0) {
        struggler = _d.back();
        _d.pop_back();
    }

    for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); it += 2) {
        d_pairs.push_back(std::make_pair(*it, *(it + 1)));
    }

    sortThePairsList(d_pairs);
    sortByFirstList(d_pairs);
    createMainChainAndPendList(d_pairs, mainChain, pend);
    indexPendList(pend, pendIndexes);
    createJacobStalList(pendIndexes, jacobStal);
    combination = creatIndexCombinationsList(pendIndexes, jacobStal);
    newPend = createNewPendList(pend, combination);
    binarySortList(mainChain, newPend, struggler);

    end = clock();
	_dequeTime = (double)(end - _start) / CLOCKS_PER_SEC * 1000000.0;
}


void PmergeMe::sort() {
	size_t size = _v.size();

	std::cout << "Before: ";
	print(_v);

	SortVector();
	_vectorTime += _dataTime;

	SortDeque();
	_dequeTime += _dataTime;

	std::cout << "After: ";
	print(sortedVector);

	std::cout << "Time ro process a range of " << size << " elements with std::vector: " << _vectorTime << " us" << std::endl;
	std::cout << "Time ro process a range of " << size << " elements with std::deque: " << _dequeTime << " us" << std::endl;
}

int stringToInt(const std::string& str) {
	if (!isNumber(str)) {
		throw std::runtime_error("Error");
	}
    char* endptr;
    long int result = strtol(str.c_str(), &endptr, 10);

    if (result < INT_MIN || result > INT_MAX) {
        throw std::runtime_error("Number is out of int range");
    }

    return static_cast<int>(result);
}

bool isNumber(const std::string& s) {
    if (s.empty()) return false;

    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (!isdigit(*it) && !(it == s.begin() && *it == '+' && s.size() > 1)) {
            return false;
        }
    }

    return true;
}

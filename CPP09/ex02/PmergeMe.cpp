/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:44:18 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/18 22:33:16 by adnane           ###   ########.fr       */
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
	std::vector<std::pair<int, int> > v_pairs;
	std::vector<int> mainChain;
	std::vector<int> pend;
	std::vector<int> pendIndexes;
	std::vector<int> jacobStal;
	int struggler;

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

	//display jacobsStal
	std::cout << "jacobStal:" << std::endl;
	for (std::vector<int>::iterator it = jacobStal.begin(); it != jacobStal.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	(void)struggler;
}

void PmergeMe::SortList() {
	clock_t start = clock();
	clock_t end;

	_l.sort();

	end = clock();
	_listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
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

void PmergeMe::sortThePairs(std::vector<std::pair<int, int> > &v_pairs) {
	std::vector<std::pair<int, int> >::iterator it = v_pairs.begin();

	while (it != v_pairs.end()) {
		if (it->first < it->second) {
			std::swap(it->first, it->second);
		}
		it++;
	}
}

void PmergeMe::sortByFirst(std::vector<std::pair<int, int> > &v_pairs) {
	std::sort(v_pairs.begin(), v_pairs.end());
}

void PmergeMe::createMainChainAndPend(std::vector<std::pair<int, int> > &v_pairs, std::vector<int> &mainChain, std::vector<int> &pend) {
	std::vector<std::pair<int, int> >::iterator it = v_pairs.begin();

	while (it != v_pairs.end()) {
		mainChain.push_back(it->first);
		pend.push_back(it->second);
		it++;
	}
}

void PmergeMe::indexPend(std::vector<int> &pend, std::vector<int> &pendIndexes) {
	std::vector<int>::iterator it = pend.begin();

	while (it != pend.end()) {
		pendIndexes.push_back(it - pend.begin());
		it++;
	}
}

void PmergeMe::createJacobStal(std::vector<int>& pendIndexes, std::vector<int>& jacobStal) {
    if (pendIndexes.empty())
        return;

    int lastIndex = pendIndexes.back();
    std::cout << "lastIndex: " << lastIndex << std::endl;
    std::cout << "pendSize: " << pendIndexes.size() << std::endl;

    int prev = 0, curr = 0, next = 0;
	int i = 0;
	
	while (next < lastIndex) {
		if (i == 0) {
			jacobStal.push_back(0);
			next = 1;
			i++;
		} else {
			next  = 2 * prev + curr;
		}
		if (next <= lastIndex) {
			jacobStal.push_back(next);
		}
		prev = curr;
		curr = next;
	}
}


void PmergeMe::sort() {
	SortVector();
	SortList();

	printVector();
	printList();
}

int stringToInt(const std::string& str) {
    char* endptr;
    long int result = strtol(str.c_str(), &endptr, 10);

    if (result < INT_MIN || result > INT_MAX) {
        throw std::runtime_error("Number is out of int range");
    }

    return static_cast<int>(result);
}

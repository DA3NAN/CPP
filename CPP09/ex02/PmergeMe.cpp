/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:44:18 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/19 20:03:42 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string const &input) {
	std::stringstream ss(input);
	std::string token;
	while (std::getline(ss, token, ' ')) {
		_v.push_back(stringToInt(token));
		_d.push_back(stringToInt(token));
	}
}

PmergeMe::PmergeMe(PmergeMe const &other) {
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
	std::vector<std::pair<int, int> > v_pairs;
	std::vector<int> mainChain, pend, newPend;
	std::vector<int> pendIndexes, jacobStal, combination;
	int struggler = -1;
	clock_t start = clock();
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
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::SortList() {
	clock_t start = clock();
	clock_t end;

	// _d.sort();

	end = clock();
	_dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
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

void PmergeMe::createMainChainAndPend(std::vector<std::pair<int, int> > &v_pairs,
							std::vector<int> &mainChain, std::vector<int> &pend) {
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

std::vector<int> PmergeMe::creatIndexCombinations(std::vector<int>& pendIndexes, std::vector<int>& jacobStal) {
    std::vector<int> combination;

    for (size_t i = 0; i < jacobStal.size(); ++i) {
        int currentNumber = jacobStal[i];

        std::vector<int>::iterator it = std::find(pendIndexes.begin(), pendIndexes.end(), currentNumber);
        if (it != pendIndexes.end()) {
            combination.push_back(currentNumber);

            *it = -1;

			for (std::vector<int>::iterator pr = it; pr != pendIndexes.begin(); pr--) {
				if (*pr != -1) {
					combination.push_back(*pr);
					*pr = -1;
				}
			}
        }
    }

    for (size_t j = 0; j < pendIndexes.size(); ++j) {
        if (pendIndexes[j] != -1) {
            combination.push_back(pendIndexes[j]);
        }
    }

	return combination;
}

std::vector<int> PmergeMe::createNewPend(std::vector<int>& pend, std::vector<int>& combination) {
	std::vector<int> newPend;

	for (size_t i = 0; i < combination.size(); ++i) {
		newPend.push_back(pend[combination[i]]);
	}

	return newPend;
}

void PmergeMe::binarySort(std::vector<int>& mainChain, std::vector<int>& newPend, int struggler) {
	for (size_t i = 0; i < newPend.size(); ++i) {
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), newPend[i]);
		mainChain.insert(it, newPend[i]);
	}
	if (struggler != -1) {
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), struggler);
		mainChain.insert(it, struggler);
	}
	sortedVector = mainChain;
}

void PmergeMe::sort() {
	size_t size = _v.size();

	std::cout << "Before: ";
	print(_v);

	SortVector();
	SortList();

	std::cout << "After: ";
	print(sortedVector);

	std::cout << "Time ro process a range of " << size << " elements with std::vector: " << _vectorTime << std::endl;
	std::cout << "Time ro process a range of " << size << " elements with std::deque: " << _dequeTime << std::endl;
}

int stringToInt(const std::string& str) {
    char* endptr;
    long int result = strtol(str.c_str(), &endptr, 10);

    if (result < INT_MIN || result > INT_MAX) {
        throw std::runtime_error("Number is out of int range");
    }

    return static_cast<int>(result);
}

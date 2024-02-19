/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:44:18 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/19 16:04:03 by adnane           ###   ########.fr       */
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
	std::vector<int> combination;
	std::vector<int> newPend;
	int struggler = -1;

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

	combination = creatIndexCombinations(pendIndexes, jacobStal);

	// Print the resulting combination
    std::cout << "Combination: ";
    for (size_t k = 0; k < combination.size(); ++k) {
        std::cout << combination[k] << " ";
    }
    std::cout << std::endl;

	newPend = createNewPend(pend, combination);

	//Print the new pend
	std::cout << "New pend: ";
	for (size_t k = 0; k < newPend.size(); ++k) {
		std::cout << newPend[k] << " ";
	}
	std::cout << std::endl;

	binarySort(mainChain, newPend, struggler);

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

std::vector<int> PmergeMe::creatIndexCombinations(std::vector<int>& pendIndexes, std::vector<int>& jacobStal) {
    std::vector<int> combination; // New combination vector

    for (size_t i = 0; i < jacobStal.size(); ++i) {
        int currentNumber = jacobStal[i];

        // Check if the current number is available in pendIndexes
        std::vector<int>::iterator it = std::find(pendIndexes.begin(), pendIndexes.end(), currentNumber);
        if (it != pendIndexes.end()) {
            // Insert the number into the combination vector
            combination.push_back(currentNumber);

            // Set the corresponding index in pendIndexes to -1
            *it = -1;

			for (std::vector<int>::iterator pr = it; pr != pendIndexes.begin(); pr--) {
				if (*pr != -1) {
					combination.push_back(*pr);
					*pr = -1;
				}
			}
        }
    }

    // Check the remaining numbers in pendIndexes
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
	// loop through the newPend vector and use lower Bound to find the position of the current element in the mainChain and then insert it
	for (size_t i = 0; i < newPend.size(); ++i) {
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), newPend[i]);
		mainChain.insert(it, newPend[i]);
	}
	// If there is a struggler, insert it in the mainChain
	if (struggler != -1) {
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), struggler);
		mainChain.insert(it, struggler);
	}
	_v = mainChain;
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

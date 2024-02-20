/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:21:55 by adnane            #+#    #+#             */
/*   Updated: 2024/02/19 20:22:31 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

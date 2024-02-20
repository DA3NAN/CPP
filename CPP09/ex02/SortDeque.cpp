/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:25:38 by adnane            #+#    #+#             */
/*   Updated: 2024/02/20 17:42:12 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::sortThePairsList(std::deque<std::pair<int, int> > &v_pairs) {
    std::deque<std::pair<int, int> >::iterator it = v_pairs.begin();

    while (it != v_pairs.end()) {
        if (it->first < it->second) {
            std::swap(it->first, it->second);
        }
        it++;
    }
}

void PmergeMe::sortByFirstList(std::deque<std::pair<int, int> > &v_pairs) {
    // Use insertion sort instead of std::sort for small containers like deques
    for (size_t i = 1; i < v_pairs.size(); ++i) {
        std::pair<int, int> temp = v_pairs[i];
        size_t j = i;
        while (j > 0 && v_pairs[j - 1] > temp) {
            v_pairs[j] = v_pairs[j - 1];
            --j;
        }
        v_pairs[j] = temp;
    }
}

void PmergeMe::createMainChainAndPendList(std::deque<std::pair<int, int> > &v_pairs,
                                     std::deque<int> &mainChain, std::deque<int> &pend) {
    std::deque<std::pair<int, int> >::iterator it = v_pairs.begin();

    while (it != v_pairs.end()) {
        mainChain.push_back(it->first);
        pend.push_back(it->second);
        it++;
    }
}

void PmergeMe::indexPendList(std::deque<int> &pend, std::deque<int> &pendIndexes) {
    std::deque<int>::iterator it = pend.begin();

    while (it != pend.end()) {
        pendIndexes.push_back(it - pend.begin());
        it++;
    }
}

void PmergeMe::createJacobStalList(std::deque<int>& pendIndexes, std::deque<int>& jacobStal) {
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
            next = 2 * prev + curr;
        }
        if (next <= lastIndex) {
            jacobStal.push_back(next);
        }
        prev = curr;
        curr = next;
    }
}

std::deque<int> PmergeMe::creatIndexCombinationsList(std::deque<int>& pendIndexes, std::deque<int>& jacobStal) {
    std::deque<int> combination;

    for (size_t i = 0; i < jacobStal.size(); ++i) {
        int currentNumber = jacobStal[i];

        std::deque<int>::iterator it = std::find(pendIndexes.begin(), pendIndexes.end(), currentNumber);
        if (it != pendIndexes.end()) {
            combination.push_back(currentNumber);

            *it = -1;

            for (std::deque<int>::iterator pr = it; pr != pendIndexes.begin(); pr--) {
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

std::deque<int> PmergeMe::createNewPendList(std::deque<int>& pend, std::deque<int>& combination) {
    std::deque<int> newPend;

    for (size_t i = 0; i < combination.size(); ++i) {
        newPend.push_back(pend[combination[i]]);
    }

    return newPend;
}

void PmergeMe::binarySortList(std::deque<int>& mainChain, std::deque<int>& newPend, int struggler) {
	for (size_t i = 0; i < newPend.size(); ++i) {
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), newPend[i]);
		mainChain.insert(it, newPend[i]);
	}
	if (struggler != -1) {
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), struggler);
		mainChain.insert(it, struggler);
	}
	sortedDeque = mainChain;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:02:44 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/19 22:40:35 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <algorithm>
# include <vector>
# include <deque>
# include <climits>
# include <ctime>
# include <iomanip>

class PmergeMe {
	private:
		std::vector<int> _v, sortedVector;
		std::deque<int> _d, sortedDeque;
		clock_t _start;
		double _dataTime;
		double _vectorTime;
		double _dequeTime;
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &other);

		void SortVector();
		void SortDeque();

		template <typename T>
		void print(T &container) {
			for (typename T::iterator it = container.begin(); it != container.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}

		void sortThePairs(std::vector<std::pair<int, int> > &v_pairs);
		void sortByFirst(std::vector<std::pair<int, int> > &v_pairs);
		void createMainChainAndPend(std::vector<std::pair<int, int> > &v_pairs, std::vector<int> &mainChain, std::vector<int> &pend);
		void indexPend(std::vector<int> &pend, std::vector<int> &pendIndexes);
		void createJacobStal(std::vector<int> &pendIndexes, std::vector<int> &jacobStal);
		std::vector<int> creatIndexCombinations(std::vector<int> &pendIndexes, std::vector<int> &jacobStal);
		std::vector<int> createNewPend(std::vector<int> &pend, std::vector<int> &combination);
		void binarySort(std::vector<int> &mainChain, std::vector<int> &newPend, int struggler);

		void sortThePairsList(std::deque<std::pair<int, int> > &v_pairs);
		void sortByFirstList(std::deque<std::pair<int, int> > &v_pairs);
		void createMainChainAndPendList(std::deque<std::pair<int, int> > &v_pairs, std::deque<int> &mainChain, std::deque<int> &pend);
		void indexPendList(std::deque<int> &pend, std::deque<int> &pendIndexes);
		void createJacobStalList(std::deque<int> &pendIndexes, std::deque<int> &jacobStal);
		std::deque<int> creatIndexCombinationsList(std::deque<int> &pendIndexes, std::deque<int> &jacobStal);
		std::deque<int> createNewPendList(std::deque<int> &pend, std::deque<int> &combination);
		void binarySortList(std::deque<int> &mainChain, std::deque<int> &newPend, int struggler);

		void sort();
};

int stringToInt(const std::string& str);
bool isNumber(const std::string &s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:02:44 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/19 20:03:36 by aait-mal         ###   ########.fr       */
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

class PmergeMe {
	private:
		std::vector<int> _v, sortedVector;
		std::deque<int> _d, sortedDeque;
		double _vectorTime;
		double _dequeTime;
	public:
		PmergeMe();
		PmergeMe(std::string const &input);
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &other);

		void SortVector();
		void SortList();

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

		void sort();
};

int stringToInt(const std::string& str);

#endif

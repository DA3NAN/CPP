/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:02:44 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/17 19:50:50 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <algorithm>
# include <vector>
# include <list>

class PmergeMe {
	private:
		std::vector<int> _v;
		std::list<int> _l;
	public:
		PmergeMe();
		PmergeMe(std::string const &input);
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &other);

		void SortVector();
		void SortList();

		void printVector() const;
		void printList() const;
};

int stringToInt(const std::string& str);

#endif

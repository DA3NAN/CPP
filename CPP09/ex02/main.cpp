/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:48:27 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/17 19:51:10 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./PmergeMe [string of numbers]" << std::endl;
		return 1;
	}

	try {
		PmergeMe p(av[1]);
		p.SortVector();
		p.SortList();
		p.printVector();
		p.printList();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

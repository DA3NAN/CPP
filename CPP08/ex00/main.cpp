/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:05:06 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/13 17:59:23 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
	}
	try {
		std::cout << easyfind(v, 5) << std::endl;
		std::cout << easyfind(l, 5) << std::endl;
		std::cout << easyfind(d, 5) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:10:44 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/10 17:31:50 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
	int x = 10, y = 0;
	float a = 10.5, b = 0.5;
	std::string s1 = "Hello", s2 = "World";

	std::cout << "x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "SWAP >> x = " << x << ", y = " << y << std::endl;
	std::cout << "MAX(x,y) = " << ::max(x, y) << std::endl;
	std::cout << "MIN(x,y) = " << ::min(x, y) << std::endl;

	std::cout << std::endl;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "SWAP >> a = " << a << ", b = " << b << std::endl;
	std::cout << "MAX(a,b) = " << ::max(a, b) << std::endl;
	std::cout << "MIN(a,b) = " << ::min(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "SWAP >> s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << "MAX(s1,s2) = " << ::max(s1, s2) << std::endl;
	std::cout << "MIN(s1,s2) = " << ::min(s1, s2) << std::endl;
	return 0;
}


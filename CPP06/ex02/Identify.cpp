/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:15 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/09 16:20:33 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base *generate(void) {
	srand(time(0));
	int i = rand() % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
	}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {
	}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {
	}
}

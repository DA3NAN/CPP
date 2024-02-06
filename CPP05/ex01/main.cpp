/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:59:11 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/06 16:12:56 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Bureaucrat b("Miloud", 1);
		Form f("7ala Madania", 1, 1);

		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat c("Jawad", 150);
		Form f("7ala Madania", 8, 1);

		std::cout << c << std::endl;
		std::cout << f << std::endl;
		while (c.getGrade() > f.getSignGrade())
			c.incrementGrade();
		f.beSigned(c);
		std::cout << c << std::endl;
		std::cout << f << std::endl;
		c.decrementGrade();
		std::cout << c << std::endl;
		c.signForm(f);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}

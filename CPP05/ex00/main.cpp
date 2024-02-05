/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:57:21 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/05 17:23:52 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat b("Miloud", 150);
	Bureaucrat c("Bouch3aib", 1);
	try {
		Bureaucrat d("Bouch3aib", 0); // it will throw an exception
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Start >> " << b << std::endl;
	try {
		b.incrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Incre >> " << b << std::endl;
	try {
		b.decrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Decre >> " << b << std::endl;
	try {
		b.decrementGrade(); // it will throw an exception
	}
	catch (const Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Decre >> " << b << std::endl;

	std::cout << std::endl;

	// c is already at the lowest grade
	std::cout << "Start >> " << c << std::endl;
	try {
		c.incrementGrade(); // it will throw an exception
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Incre >> " << c << std::endl;

	return (0);
}

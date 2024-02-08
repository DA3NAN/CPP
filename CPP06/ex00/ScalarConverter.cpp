/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:32 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/08 16:33:37 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {
	(void)src;
	return *this;
}

const char* ScalarConverter::ImpossibleException::what() const throw() {
	return "impossible";
}

const char* ScalarConverter::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

void ScalarConverter::printChar(char c) {
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		throw NonDisplayableException();
}

void ScalarConverter::printInt(int i) {
	std::cout << "int: ";
	std::cout << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}



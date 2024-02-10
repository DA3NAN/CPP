/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:32 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/10 14:25:55 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Parsing.hpp"
#include "Conversion.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {
	(void)src;
	return *this;
}

void ScalarConverter::convert(std::string const & str) {
	try {
		if (!isValid(str)) {
			throw std::runtime_error("Not a valid input");
		}

		if (specialCase(str))
			return;

		try {
			std::cout << "char: ";
			char c = stringToChar(str);
			printChar(c);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "int: ";
			int i = stringToInt(str);
			printInt(i);
		}  catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "float: ";
			float f = stringToFloat(str);
			printFloat(f);
		}catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "double: ";
			double d = stringToDouble(str);
			printDouble(d);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void printChar(char c) {
	std::cout << "'" << c << "'" << std::endl;
}

void printInt(int i) {
	std::cout << i << std::endl;
}

void printFloat(float f) {
	if (f - static_cast<int>(f) == 0)
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void printDouble(double d) {
	if (d - static_cast<int>(d) == 0)
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << d << std::endl;
}


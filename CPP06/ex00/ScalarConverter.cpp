/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:32 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/10 00:49:57 by adnane           ###   ########.fr       */
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
			char c = static_cast<char>(std::atoi(str.c_str()));
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
	unsigned char uc = static_cast<unsigned char>(c);

	if (uc > 127)
		throw std::runtime_error("impossible");
	else if (!isprint(uc))
		throw std::runtime_error("Non displayable");
	else
		std::cout << "'" << uc << "'" << std::endl;
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


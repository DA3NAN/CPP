/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:32 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/08 19:09:43 by aait-mal         ###   ########.fr       */
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

void ScalarConverter::convert(std::string const & str) {
	try {
		if (!isValid(str)) {
			throw NotValidException();
		}

		if (specialCase(str))
			return;

		try {
			char c = static_cast<char>(std::stoi(str));
			printChar(c);
		} catch (std::exception & e) {
			std::cout << "char: " << e.what() << std::endl;
		}

		// try {
		// 	int i = std::stoi(str);
		// 	printInt(i);
		// } catch (std::exception & e) {
		// 	std::cout << "int: " << e.what() << std::endl;
		// }

		// try {
		// 	float f = std::stof(str);
		// 	printFloat(f);
		// } catch (std::exception & e) {
		// 	std::cout << "float: " << e.what() << std::endl;
		// }

		// try {
		// 	double d = std::stod(str);
		// 	printDouble(d);
		// } catch (std::exception & e) {
		// 	std::cout << "double: " << e.what() << std::endl;
		// }
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

bool isValid(std::string const & str) {
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	if (str.length() >= 1 && (isdigit(str[0]) || str[0] == '-' || str[0] == '+')) {
		size_t i = 0;
		if (str[i] == '-' || str[i] == '+')
			i++;
		for (; i < str.length(); i++) {
			if (isdigit(str[i])
				|| (str[i] == '.'
					&& str[i + 1] && str[i + 1] != '.'
					&& str[i + 1] != 'f'
					&& i != str.length() - 1)
				|| (str[i] == 'f' && i == str.length() - 1)
				)
				continue;
			else
				return false;
		}
		return true;
	}
	return false;
}

void printChar(char c) {
	if (c > 127 || c < 0)
		throw ScalarConverter::ImpossibleException();
	else if (!isprint(c))
		throw ScalarConverter::NonDisplayableException();
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

bool specialCase(std::string const & str) {
	if (str == "-inff" || str == "+inff" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		return true;
	}
	if (str == "-inf" || str == "+inf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return true;
	}
	return false;
}

const char * ScalarConverter::NotValidException::what() const throw() {
	return "Not a valid input";
}

const char * ScalarConverter::ImpossibleException::what() const throw() {
	return "impossible";
}

const char * ScalarConverter::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

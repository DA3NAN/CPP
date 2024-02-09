/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:32 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/09 18:44:53 by aait-mal         ###   ########.fr       */
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
			std::cout << "char: ";
			char c = static_cast<char>(std::stoi(str));
			printChar(c);
		} catch(std::out_of_range) {
			std::cout << "impossible" << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "int: ";
			int i = std::stoi(str);
			printInt(i);
		} catch (std::out_of_range) {
			std::cout << "impossible" << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "float: ";
			float f = std::stod(str);
			printFloat(f);
		} catch(std::out_of_range) {
			std::cout << "impossible" << std::endl;

		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "double: ";
			double d = std::stod(str);
			printDouble(d);
		} catch(std::out_of_range) {
			std::cout << "impossible" << std::endl;

		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void printChar(char c) {
	if (c > 127 || c < 0)
		throw ScalarConverter::ImpossibleException();
	else if (!isprint(c))
		throw ScalarConverter::NonDisplayableException();
	else
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

bool specialCase(std::string const & str) {
	if (str.length() == 1 && !isdigit(str[0])) {
		std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
		return true;
	} else if (str == "-inff" || str == "+inff" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		return true;
	} else if (str == "-inf" || str == "+inf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return true;
	}
	return false;
}

bool isValid(std::string const & str) {
	int	pointCount = 0;

	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	if (isOctalLiteral(str))
		return false;
	if (str.length() >= 1 && (isdigit(str[0]) || str[0] == '-' || str[0] == '+')) {
		size_t i = 0;
		if (str[i] == '-' || str[i] == '+')
			i++;

		for (size_t j = i; j < str.length(); j++) {
			if (str[j] == '.')
				pointCount++;
		}
		if (pointCount > 1)
			return false;

		for (; i < str.length(); i++) {
			if (isdigit(str[i])
				|| (str[i] == '.'
					&& str[i - 1] && isdigit(str[i - 1])
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

bool isOctalLiteral(const std::string& str) {
    if (str.empty() || str[0] != '0' || (str.length() == 1 && str[0] == '0')) {
        return false;
    }

    std::istringstream iss(str);
    int num;
    iss >> std::oct >> num;

    return !iss.fail() && iss.eof();
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

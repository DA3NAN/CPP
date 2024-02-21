/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:41:31 by adnane            #+#    #+#             */
/*   Updated: 2024/02/21 19:41:22 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::ifstream &file, char separator) {
	std::string line;
	std::string date;
	double rate;

	 // Check if the file is empty
    if (file.peek() == std::ifstream::traits_type::eof()) {
        throw std::runtime_error("Error: Empty data csv file");
    }

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, separator);
		ss >> rate;
		_data.insert(std::pair<std::string, double>(date, rate));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src)
		_data = src._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getRate(std::string date) {
    std::multimap<std::string, double>::iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date) {
        return it->second;
    }
    if (it == _data.begin() || it == _data.end()) {
        return HUGE_VAL;
    }
    --it;

    return it->second;
}

void TreatInput(std::ifstream &file, BitcoinExchange &exchange, char separator) {
    std::string line;
	int skip = 0;

    while (std::getline(file, line)) {
		if (skip == 0) {
			if (line == "date | value") {
				skip = 1;
				continue;
			} else {
				std::cerr << "Error: bad input file." << std::endl;
				return;
			}
		}
        std::istringstream iss(line);
		//chck if line is empty or just white spaces
		if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
			std::cerr << "Error: empty line." << std::endl;
			continue;
		}
        std::string date;
		std::string valueStr;
        double value;

        std::getline(iss, date, separator);
		if (parseDateWhitespaces(date) == 1) {
			std::cerr << "Error: bad line: Usage: [date | value]" << std::endl;
			continue;
		}
		removeWhitespace(date);
		std::getline(iss, valueStr);
		if (parseValueWhitespaces(valueStr) == 1) {
			std::cerr << "Error: bad line: Usage: [date | value]" << std::endl;
			continue;
		}
		removeWhitespace(valueStr);
		std::stringstream valueStream(valueStr);

		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
            continue;
        } else if (!(valueStream >> value) || !valueStream.eof()) {
            std::cout << "Error: not a valid number." << std::endl;
            continue;
        } else if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		} else if (value > 1000) {
			std::cout << "Error: too large number." << std::endl;
			continue;
		}

        double rate = exchange.getRate(date);
		if (rate == HUGE_VAL) {
			std::cout << "Error: no data for date => " << date << std::endl;
			continue;
		}

    	double result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}

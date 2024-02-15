/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:46:09 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/15 19:36:14 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::ifstream & data, char delim) {
	std::string line;
	int i = 0;

	while (std::getline(data, line)) {
		if (i == 0) {
			i++;
			continue;
		}
		_bitcoin.insert(split(line, delim));
		i++;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & exchange) {
	*this = exchange;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & exchange) {
	if (this != &exchange) {
		_bitcoin = exchange._bitcoin;
	}
	return (*this);
}

double BitcoinExchange::getRate(std::string const & date) const {
	std::map<std::string, double>::const_iterator it = _bitcoin.find(date);
	if (it != _bitcoin.end()) {
		return (it->second);
	}
	return (0);
}

double BitcoinExchange::convert(std::string const & date, double amount) const {
	double rate = getRate(date);
	if (rate > 0) {
		return (amount * rate);
	}
	return (0);
}

void BitcoinExchange::printMap() const {
    std::map<std::string, double>::const_iterator it = _bitcoin.begin();
    while (it != _bitcoin.end()) {
        std::cout << it->first << "," << std::fixed << std::setprecision(2) << it->second << std::endl;
        it++;
    }
}

std::pair<std::string, double> split(const std::string& line, char delim) {
    std::pair<std::string, double> result;
    std::string date;
    std::string rateStr;
    double rate;

    std::istringstream ss(line);
    std::getline(ss, date, delim);
    std::getline(ss, rateStr);

    std::istringstream(rateStr) >> rate;

    result.first = date;
    result.second = rate;

    return result;
}


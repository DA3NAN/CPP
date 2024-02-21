/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:18:14 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/21 19:21:36 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <algorithm>
# include <ctime>
# include <cmath>
# include <climits>

class BitcoinExchange {
	private:
		std::map<std::string, double> _data;
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream &file, char separator);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		double getRate(std::string date);
};

void TreatInput(std::ifstream &file, BitcoinExchange &exchange, char separator);
void removeWhitespace(std::string& str);
int parseDateWhitespaces(const std::string& str);
int parseValueWhitespaces(const std::string& str);
bool isValidDate(const std::string& date);

#endif

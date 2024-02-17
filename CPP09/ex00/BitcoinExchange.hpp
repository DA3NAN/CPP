/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:18:14 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/17 02:53:31 by adnane           ###   ########.fr       */
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
		std::multimap<std::string, double> _data;
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream &file, char separator);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		double getRate(std::string date);
		void printMap();
};

void TreatInput(std::ifstream &file, BitcoinExchange &exchange, char separator);
void removeWhitespace(std::string& str);
bool isValidDate(const std::string& date);

#endif

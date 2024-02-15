/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:18:14 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/15 19:38:52 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>

class BitcoinExchange {
	private:
		std::multimap<std::string, double> _bitcoin;
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream & data, char delim);
		BitcoinExchange(BitcoinExchange const & exchange);
		~BitcoinExchange();
		BitcoinExchange & operator=(BitcoinExchange const & exchange);
		double getRate(std::string const & date) const;
		double convert(std::string const & date, double amount) const;
		void printMap() const;
};

std::pair<std::string, double> split(std::string const & line, char delim);

#endif

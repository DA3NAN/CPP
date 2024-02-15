/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:31:55 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/15 19:36:37 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	std::ifstream dataFile("data.csv");
	std::ifstream inputFile(argv[1]);

	if (!dataFile.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return (1);
	}
	else if (!inputFile.is_open()) {
		std::cerr << "Error: could not open input file." << std::endl;
		return (1);
	}

	BitcoinExchange exchange(dataFile, ',');
	BitcoinExchange input(inputFile, '|');
	dataFile.close();
	inputFile.close();

	input.printMap();

	return (0);
}

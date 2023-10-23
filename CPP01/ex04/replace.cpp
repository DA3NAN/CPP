/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:23:20 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/22 18:12:56 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	replace(std::string filename, std::string s1, std::string s2) {
	std::ifstream input(filename.c_str());
	if (!input.is_open()) {
		std::cerr << "Error: cannot open input file " << filename << std::endl;
		return ;
	}

	std::string output_fileName = filename + ".replace";
	std::ofstream output(output_fileName.c_str());
	if (!output.is_open()) {
		std::cerr << "Error: cannot open output file " << output_fileName << std::endl;
		return ;
	}

	std::string line;
	std::string newLine;
	while (std::getline(input, line)) {
		if (input.fail()) {
			std::cerr << "Error: cannot read from file " << filename << std::endl;
			return ;
		}

		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			newLine = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			line = newLine;
			pos += s2.length();
		}
		if (input.eof())
			output << line;
		else if (!input.eof())
			output << line << std::endl;
		if (output.fail()) {
			std::cerr << "Error: cannot write to file " << output_fileName << std::endl;
			return ;
		}
	}
	input.close();
	output.close();
}

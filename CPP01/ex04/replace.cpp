/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:23:20 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/27 17:13:27 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	replace(std::string filename, std::string s1, std::string s2) {
	if (s1.empty()) {
		std::cerr << "Error: empty string" << std::endl;
		return ;
	}
	std::ifstream input(filename.c_str());
	if (!input.is_open()) {
		std::cerr << "Error: cannot open input file " << filename << std::endl;
		return (input.close());
	}

	std::string output_fileName = filename + ".replace";
	std::ofstream output(output_fileName.c_str());
	if (!output.is_open()) {
		std::cerr << "Error: cannot open output file " << output_fileName << std::endl;
		return (input.close(), output.close());
	}

	std::string line;
	while (std::getline(input, line)) {
		if (input.fail()) {
			std::cerr << "Error: cannot read from file " << filename << std::endl;
			return (input.close(), output.close());
		}

		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		output << line;
		if (!input.eof())
			output << std::endl;
		if (output.fail()) {
			std::cerr << "Error: cannot write to file " << output_fileName << std::endl;
			return (input.close(), output.close());
		}
	}
	input.close();
	output.close();
}

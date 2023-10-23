/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:19:16 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/23 12:50:18 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	level_code(std::string level) {
	if (level == "DEBUG")
		return (0);
	else if (level == "INFO")
		return (1);
	else if (level == "WARNING")
		return (2);
	else if (level == "ERROR")
		return (3);
	return (-1);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./HarlFilter <level>" << std::endl;
		return 1;
	}
	std::string level = argv[1];
    Harl harl;
	int levelCode = level_code(level);

	for (int i = levelCode; i < 4; i++) {
		switch (i) {
			case 0:
				harl.complain("DEBUG");
				break;
			case 1:
				harl.complain("INFO");
				break;
			case 2:
				harl.complain("WARNING");
				break;
			case 3:
				harl.complain("ERROR");
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				return (1);
		}
	}

	return (0);
}

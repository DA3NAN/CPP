/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:19:16 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/24 16:25:02 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./HarlFilter <level>" << std::endl;
		return 1;
	}

	std::string level = argv[1];
    Harl harl;

	harl.complain(level);
	return (0);
}

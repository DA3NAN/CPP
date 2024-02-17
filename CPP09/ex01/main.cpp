/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:51:50 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/17 16:17:42 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"[expression]\"" << std::endl;
		return (1);
	}

	try {
		RPN rpn(argv[1]);
		rpn.calculate();
		rpn.printResult();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}

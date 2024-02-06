/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:27:35 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/06 19:33:12 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* form;

	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Zlatan");
		scf = someRandomIntern.makeForm("shrubbery creation", "home");
		form = someRandomIntern.makeForm("random", "home");

		std::cout << *rrf << std::endl;
		std::cout << *ppf << std::endl;
		std::cout << *scf << std::endl;
		std::cout << *form << std::endl;

		delete rrf;
		delete ppf;
		delete scf;
		delete form;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

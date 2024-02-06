/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:29:42 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/06 17:49:04 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main() {
	Bureaucrat a("A", 1);
	Bureaucrat b("B", 72);
	ShrubberyCreationForm Shru("home");
	PresidentialPardonForm Pres("home");
	RobotomyRequestForm Robo("home");

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Shru << std::endl;
	std::cout << Pres << std::endl;
	std::cout << Robo << std::endl;

	std::cout << std::endl;

	a.signForm(Shru);
	a.executeForm(Shru);

	std::cout << std::endl;

	b.signForm(Shru);
	b.executeForm(Shru);

	std::cout << std::endl;

	a.signForm(Pres);
	a.executeForm(Pres);

	std::cout << std::endl;

	b.signForm(Pres);
	b.executeForm(Pres);

	std::cout << std::endl;

	a.signForm(Robo);
	a.executeForm(Robo);

	std::cout << std::endl;

	b.signForm(Robo);
	b.executeForm(Robo);
	return 0;
}

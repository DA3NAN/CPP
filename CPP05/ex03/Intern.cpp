/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:21:34 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/06 19:31:29 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src) {
	*this = src;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & src) {
	(void)src;
	return *this;
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
	const std::string forms[3] = { "shrubbery creation", "presidential pardon", "robotomy request" };

	int i;
	for (i = 0; i < 3 && forms[i] != name; i++);
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return new PresidentialPardonForm(target);
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return new RobotomyRequestForm(target);
		default:
			throw Intern::FormNotFoundException();
	}
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

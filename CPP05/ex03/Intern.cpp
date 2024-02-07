/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:21:34 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/07 16:11:57 by aait-mal         ###   ########.fr       */
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

AForm *Intern::makeShrubberyCreationForm(std::string const name, std::string const &target) {
	std::cout << "Intern creates " << name << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string const name, std::string const &target) {
	std::cout << "Intern creates " << name << std::endl;
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string const name, std::string const &target) {
	std::cout << "Intern creates " << name << std::endl;
	return new RobotomyRequestForm(target);
}


AForm *Intern::makeForm(std::string const &name, std::string const &target) {
	AForm *(Intern::*forms[3])(std::string const, std::string const &) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm
	};
	std::string names[3] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"
	};
	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			return (this->*forms[i])(name, target);
		}
	}
	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

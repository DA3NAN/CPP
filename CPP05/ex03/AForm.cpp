/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:57:19 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/07 16:06:46 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(std::string const &name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _executeGrade(src._executeGrade) {}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const & src) {
	if (this != &src)
		_signed = src.getSigned();
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecuteGrade() const {
	return _executeGrade;
}

void AForm::beSigned(Bureaucrat const & b) {
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream & operator<<(std::ostream & os, AForm const & f) {
	os << f.getName() << " form is " << (f.getSigned() ? "signed" : "not signed") << ", " << f.getSignGrade() << " to be signed, and " << f.getExecuteGrade() << " to be executed";
	return os;
}

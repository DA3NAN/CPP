/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:34:42 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/02 13:14:55 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) {
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & src) {
	std::cout << "AAnimal Copy Assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

std::string AAnimal::getType() const {
	return (this->type);
}

void AAnimal::setType(std::string type) {
	this->type = type;
}

void AAnimal::makeSound() const {
	std::cout << "I am a Square!!" << std::endl;
}

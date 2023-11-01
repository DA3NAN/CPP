/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:34:42 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 17:51:41 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

A_Animal::A_Animal() {
}

A_Animal::A_Animal(A_Animal const & src) {
	*this = src;
}

A_Animal::~A_Animal() {
}

A_Animal & A_Animal::operator=(A_Animal const & src) {
	if (this != &src)
		this->type = src.type;
	return (*this);
}

std::string A_Animal::getType() const {
	return (this->type);
}

void A_Animal::setType(std::string type) {
	this->type = type;
}

void A_Animal::makeSound() const {
	std::cout << "I am a Square!!" << std::endl;
}

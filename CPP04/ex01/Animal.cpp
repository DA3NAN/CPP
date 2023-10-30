/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:16:56 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/30 15:31:44 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal Parametric constructor called" << std::endl;
}

Animal::Animal(Animal const & src) {
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal & Animal::operator=(Animal const & src) {
	std::cout << "Animal Copy Assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::makeSound() const {
	std::cout << "Animal Sound :|" << std::endl;
}

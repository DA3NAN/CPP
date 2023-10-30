/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:32 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/30 15:34:23 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(Dog const & src) {
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & src) {
	std::cout << "Dog Copy Assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "bark bark!!" << std::endl;
}

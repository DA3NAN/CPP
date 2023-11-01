/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:25:52 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 18:36:03 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat const & src) {
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & src) {
	std::cout << "Cat Copy Assignment operator called" << std::endl;
	if (this != &src) {
        this->type = src.type;
		if (this->brain)
        	delete this->brain;
        this->brain = new Brain(*(src.brain));
    }
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "meow meow!!" << std::endl;
}
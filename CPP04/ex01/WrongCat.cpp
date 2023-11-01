/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:25:02 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/30 17:27:10 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) {
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & src) {
	std::cout << "WrongCat Copy Assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "bark bark!!" << std::endl;
}

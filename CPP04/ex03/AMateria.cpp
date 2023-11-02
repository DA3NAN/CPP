/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:27:49 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 21:26:24 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(std::string const & type) : type(type) {
}

AMateria::AMateria(AMateria const & src) {
	*this = src;
}

AMateria::~AMateria() {
}

AMateria & AMateria::operator=(AMateria const & src) {
	if (this != &src)
		this->type = src.type;
	return (*this);
}

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses " << this->type << " at " << target.getName() << " *" << std::endl;
}


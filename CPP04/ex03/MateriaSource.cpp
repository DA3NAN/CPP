/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:22 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 21:30:42 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	this->count = 0;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src) {
	if (this != &src)
	{
		this->count = src.count;
		for (int i = 0; i < this->count; i++)
			this->materias[i] = src.materias[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	if (this->count < 4)
	{
		this->materias[this->count] = m;
		this->count++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->count; i++)
		if (this->materias[i]->getType() == type)
			return (this->materias[i]->clone());
	return (NULL);
}

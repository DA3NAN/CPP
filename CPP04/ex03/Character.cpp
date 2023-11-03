/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:46:55 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/03 18:26:05 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("default") {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const & name) : name(name) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const & src) {
	*this = src;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
		if (this->unequiped[i])
			delete this->unequiped[i];
	}
}

Character & Character::operator=(Character const & src) {
	if (this != &src) {
		this->name = src.name;
		for (int i = 0; i < 4; i++)
			if (this->inventory[i])
				delete this->inventory[i];
		for (int i = 0; i < 4; i++)
			if (src.inventory[i])
				this->inventory[i] = src.inventory[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			break ;
		}
		else if (i == 3)
			std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		for (int i = 0; i < 4; i++)
			if (!this->unequiped[i]) {
				this->unequiped[i] = this->inventory[idx];
				break ;
			}
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:18:05 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/25 15:08:01 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->weapon = NULL;
	this->name = name;
}

HumanB::~HumanB() {
}

void HumanB::attack() {
	std::cout << this->name << " attacks with his ";
	if (this->weapon)
		std::cout << this->weapon->getType();
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

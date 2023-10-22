/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:07:38 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/22 15:23:21 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {
	this->name = name;
}

HumanA::~HumanA() {
}

void HumanA::attack() {
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

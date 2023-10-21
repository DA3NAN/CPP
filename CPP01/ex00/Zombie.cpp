/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:08:13 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/21 19:16:46 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie(void) {
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce(void) {
	std::cout <<  this->name  <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}

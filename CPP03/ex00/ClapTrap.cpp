/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:44:37 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/28 19:05:08 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->energyPoints = src.energyPoints;
		this->attackDamage = src.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(std::string const & target) {
	if (this->energyPoints < 1) {
		std::cout << "ClapTrap " << this->name << " has no energy points!" << std::endl;
		return ;
	}
	if (this->hitPoints < 1) {
		std::cout << "ClapTrap " << this->name << " is dead, can't attack!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints < 1) {
		std::cout << "ClapTrap " << this->name << " is dead, can't take more damage!" << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! ";
	if (this->hitPoints < 1) {
		std::cout << this->name << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->hitPoints << " hitPoints left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints < 1) {
		std::cout << "ClapTrap " << this->name << " has no energy points!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " has been repaired with " << amount << " hitPoints! Now has " << this->hitPoints << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:48:43 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/29 15:30:58 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->energyPoints = src.energyPoints;
		this->attackDamage = src.attackDamage;
	}
	return *this;
}

void ScavTrap::attack(std::string const & target) {
	if (this->energyPoints < 1) {
		std::cout << "ScavTrap " << this->name << " has no energy points!" << std::endl;
		return ;
	}
	if (this->hitPoints < 1) {
		std::cout << "ScavTrap " << this->name << " is powered off, can't attack!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", with thye mighty SCAVEPUNCH causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints < 1) {
		std::cout << "ScavTrap " << this->name << " is powered off, can't take more damage!" << std::endl;
		return ;
	}
	if (this->hitPoints < (int)amount) {
		this->hitPoints = 0;
		std::cout << "ScavTrap " << this->name << " is powered off!" << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << "ScavTrap " << this->name << " takes " << amount << " points of damage! ";
	if (this->hitPoints < 1) {
		std::cout << this->name << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->hitPoints << " hitPoints left" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints < 1) {
		std::cout << "ScavTrap " << this->name << " has no energy points!" << std::endl;
		return ;
	}
	this->hitPoints += amount;
	if (this->hitPoints > 100)
		this->hitPoints = 100;
	std::cout << "ScavTrap " << this->name << " is charged with " << amount << " hitPoints! Now has " << this->hitPoints << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " has entered the Gate keeper mode!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:17:51 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/02 15:55:27 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->energyPoints = src.energyPoints;
		this->attackDamage = src.attackDamage;
	}
	return *this;
}

void FragTrap::attack(std::string const & target) {
	if (this->energyPoints < 1) {
		std::cout << "FragTrap " << this->name << " has no energy points!" << std::endl;
		return ;
	}
	if (this->hitPoints < 1) {
		std::cout << "FragTrap " << this->name << " is fragged off, can't attack!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "FragTrap " << this->name << " attacks " << target << ", with the FRAGGYPUNCH causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints < 1) {
		std::cout << "FragTrap " << this->name << " is fragged off, can't take more damage!" << std::endl;
		return ;
	}
	this->hitPoints = ((int)amount >= this->hitPoints) ? 0 : (this->hitPoints - amount);
	std::cout << "FragTrap " << this->name << " takes " << amount << " points of damage! ";
	if (this->hitPoints < 1) {
		std::cout << this->name << " is fragged off!" << std::endl;
		return ;
	}
	std::cout << this->name << " has " << this->hitPoints << " hit points left!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints < 1) {
		std::cout << "FragTrap " << this->name << " has no energy points!" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	(this->hitPoints + amount) > 100 ? this->hitPoints = 100 : this->hitPoints += amount;
	std::cout << "FragTrap " << this->name << " is repaired with " << amount << " hitPoints! Now has " << this->hitPoints << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " wants to high five you!" << std::endl;
}

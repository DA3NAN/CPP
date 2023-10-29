/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:06:45 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/29 21:55:41 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("a");
	ScavTrap b("b");
	ClapTrap *c = new ScavTrap("c");

	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(20);
	b.attack("a");
	a.takeDamage(20);
	a.guardGate();
	b.guardGate();
	std::cout << std::endl;

	c->attack("b");
	b.takeDamage(20);
	b.attack("c");
	c->takeDamage(20);
	c->takeDamage(20);
	c->beRepaired(20);
	// c->guardGate();
	std::cout << std::endl;

	return 0;
}

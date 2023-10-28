/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:51:30 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/28 19:04:33 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapTrap("Al3arbi");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3("Ba3bou3");

	clapTrap3 = clapTrap2;

	std::cout << std::endl;
	clapTrap.attack("Charmouta");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(10);
	clapTrap.attack("Charmouta");
	clapTrap.takeDamage(7);
	clapTrap.takeDamage(8);
	clapTrap.takeDamage(10);
	clapTrap.attack("Charmouta");
	clapTrap.beRepaired(10);
	clapTrap.attack("Charmouta");
	std::cout << std::endl;

	return (0);
}

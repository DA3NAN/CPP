/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:22:38 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/02 15:55:38 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap frag("FRAGGY");
	FragTrap frag2("BADASS");
	ScavTrap scav("CHATGPT");
	ScavTrap scav2("MIDJOURNEY");

	std::cout << std::endl;
	frag.attack("BADASS");
	frag2.takeDamage(30);
	std::cout << std::endl;
	
	frag.attack("BADASS");
	frag2.takeDamage(30);
	std::cout << std::endl;

	frag2.beRepaired(10);
	frag2.attack("FRAGGY");
	frag.takeDamage(30);
	std::cout << std::endl;
	
	frag2.attack("MIDJOURNEY");
	scav2.takeDamage(30);
	std::cout << std::endl;

	scav.attack("BADASS");
	frag2.takeDamage(20);
	scav2.attack("BADASS");
	frag2.takeDamage(20);
	scav2.attack("BADASS");
	frag2.takeDamage(20);
	std::cout << std::endl;
	
	frag2.beRepaired(10);
	frag2.beRepaired(10);
	frag2.beRepaired(150);
	frag2.highFivesGuys();
	scav2.guardGate();
	std::cout << std::endl;
	
	return (0);
}

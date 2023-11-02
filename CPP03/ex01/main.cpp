/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:06:45 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/02 15:30:16 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("CHATGPT");
	ScavTrap b("MIDJOURNEY");

	std::cout << std::endl;
	a.attack("MIDJOURNEY");
	b.takeDamage(20);
	a.attack("MIDJOURNEY");
	b.takeDamage(20);
	a.attack("MIDJOURNEY");
	b.takeDamage(20);
	a.attack("MIDJOURNEY");
	b.takeDamage(20);
	a.attack("MIDJOURNEY");
	b.takeDamage(20);
	std::cout << std::endl;
	
	b.attack("CHATGPT");
	b.beRepaired(10);
	b.attack("CHATGPT");
	a.takeDamage(20);
	std::cout << std::endl;

	a.guardGate();
	b.guardGate();
	std::cout << std::endl;

	return 0;
}

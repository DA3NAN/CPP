/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:51:30 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/29 21:13:39 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("Ba3bou3");
	ClapTrap clap2("Charmouta");
	ClapTrap clap3(clap);
	ClapTrap clap4;

	clap4 = clap2;

	std::cout << std::endl;
	clap.attack("Charmouta");
	clap.attack("Charmouta");
	clap.attack("Charmouta");
	clap.attack("Charmouta");
	clap.attack("Charmouta");
	clap.attack("Charmouta");
	clap.attack("Charmouta");
	clap.attack("Charmouta");
	clap2.takeDamage(0);
	clap2.attack("Ba3bou3");
	clap.takeDamage(0);
	clap.beRepaired(10);
	clap2.attack("Ba3bou3");
	clap.takeDamage(0);
	clap.beRepaired(5);
	clap.attack("Charmouta");
	clap.beRepaired(10);
	std::cout << std::endl;

	clap4.attack("Ba3bou3");
	clap3.takeDamage(10);
	clap3.attack("Charmouta");
	clap3.beRepaired(10);
	clap3.attack("Charmouta");
	clap4.takeDamage(10);
	std::cout << std::endl;


	return (0);
}

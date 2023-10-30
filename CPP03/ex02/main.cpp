/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:22:38 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/30 15:13:06 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag("Fraggy");
	FragTrap frag2("Badass");
	FragTrap frag3;
	frag3 = frag2;
	
	std::cout << std::endl;
	frag.attack("Badass");
	frag2.takeDamage(30);
	frag2.attack("Fraggy");
	frag.takeDamage(30);
	frag2.beRepaired(10);
	frag.beRepaired(10);
	frag.highFivesGuys();
	std::cout << std::endl;
	
	return (0);
}
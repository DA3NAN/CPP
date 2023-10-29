/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:22:38 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/29 16:23:25 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag("Fraggy");
	FragTrap frag2(frag);
	FragTrap frag3;
	frag3 = frag2;
	
	std::cout << std::endl;
	frag.attack("Badass");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();
	std::cout << std::endl;
	
	return (0);
}
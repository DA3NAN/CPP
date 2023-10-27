/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:15:20 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/27 17:18:27 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *zombie = newZombie("zombie");
	if (!zombie)
		return (1);
	zombie->announce();
	randomChump("zombie");
	delete zombie;
	return (0);
}

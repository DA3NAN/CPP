/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:15:20 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/21 19:52:37 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int N = 10;
	Zombie *zombies = zombieHorde(N, "zombie");

	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete [] zombies;
	return 0;
}

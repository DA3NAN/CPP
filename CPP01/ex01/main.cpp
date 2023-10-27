/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:15:20 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/27 17:19:55 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int N = 10;
	Zombie *zombies = zombieHorde(N, "zombie");
	if (!zombies)
		return (1);

	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete [] zombies;
	return 0;
}

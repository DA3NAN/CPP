/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:06:06 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/23 14:38:55 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif

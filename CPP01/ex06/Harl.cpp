/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:21:35 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/23 16:34:12 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. \
You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. \
I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*ptr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	int i;
	for (i = 0; i < 4 && levels[i] != level; i++);
	switch (i)
	{
		case 0:
			(this->*ptr[i])();
			i++;
		case 1:
			(this->*ptr[i])();
			i++;
		case 2:
			(this->*ptr[i])();
			i++;
		case 3:
			(this->*ptr[i])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

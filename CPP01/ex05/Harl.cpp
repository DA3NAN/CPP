/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:26:11 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/24 13:02:47 by aait-mal         ###   ########.fr       */
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

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			(this->*ptr[i])();
	}
}

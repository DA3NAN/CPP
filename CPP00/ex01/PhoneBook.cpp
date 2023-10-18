/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:46:38 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/18 19:04:01 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact(int index) {
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	contact[index].setData(firstName, lastName, nickName, phoneNumber, darkestSecret);
	return ;
}

void PhoneBook::serachContact(void) {
	std::string indexString;
	int i;

	std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "      Index | First name |  Last name |     Nickname" << std::endl;
	for (i = 0; i < 8; i++)
		contact[i].displayData(i);
	std::cout << "----------------------------------------------------" << std::endl;
	
	std::cout << "Enter index (1 - 8): ";
	std::getline(std::cin, indexString);
	i = std::atoi(indexString.c_str());
	if (std::cin.eof())
        exit(0) ;
	if (i < 1 || i > 8)
		std::cout << "Invalid index" << std::endl;
	else {
		std::cout << "----------------------------------------------------" << std::endl;
    	std::cout << "      Index | First name |  Last name |     Nickname" << std::endl;
		contact[i - 1].displayData(i - 1);
		std::cout << "----------------------------------------------------" << std::endl;
	}
}
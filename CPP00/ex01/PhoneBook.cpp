/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:46:38 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 18:16:41 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	isStringNumbers(std::string number) {
	for (int i = 0; i < (int)number.length(); i++)
		if (number[i] < '0' || number[i] > '9') {
			std::cout << "\033[1;31m";
			std::cout << "Phone number must contain only numbers" << std::endl;
			std::cout << "\033[0m";
			return (false);
		}
	return (true);
}

void PhoneBook::addContact(int index) {
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	do {
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
		EOF_IGNORE
	} while (firstName.empty());
	do {
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
		EOF_IGNORE
	} while (lastName.empty());
	do {
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickName);
		EOF_IGNORE
	} while (nickName.empty());
	do {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
		EOF_IGNORE
	} while (phoneNumber.empty() || !isStringNumbers(phoneNumber));
	do {
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
		EOF_IGNORE
	} while (darkestSecret.empty());
	std::cout << std::endl;
	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "\033[1;31m";
		std::cout << "All inputs must be filled" << std::endl << std::endl;
		std::cout << "\033[0m";
		return ;
	}
	contact[index].setData(firstName, lastName, nickName, phoneNumber, darkestSecret);
	return ;
}

void PhoneBook::serachContact(void) {
	std::string indexString;
	int i;

	if (contact[0].isEmpty()) {
		std::cout << "\033[1;31m";
		std::cout << "No contacts found" << std::endl << std::endl;
		std::cout << "\033[0m";
		return ;
	}
	else {
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "    Index |First name| Last name|  Nickname" << std::endl;
		for (i = 0; i < 8; i++)
			if (!contact[i].isEmpty())
				contact[i].displayData(i);
		std::cout << "-------------------------------------------" << std::endl;
	
		std::cout << "Enter index (1 - 8): ";
		std::getline(std::cin, indexString);
		EOF_IGNORE
		if (indexString.length() > 1 || indexString[0] < '1' || indexString[0] > '8') {
			std::cout << "\033[1;31m";
			std::cout << "Invalid index" << std::endl << std::endl;
			std::cout << "\033[0m";
			return ;
		}
		i = indexString[0] - '0';
		contact[i - 1].displayDataExtended();
	}
	
}
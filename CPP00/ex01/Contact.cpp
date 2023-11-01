/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:52:31 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 18:15:48 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

void	Contact::setData(std::string firstName, std::string lastName, std::string nickName,
	    std::string phoneNumber, std::string darkestSecret) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
    return ;
}

void	Contact::displayData(int index) {
    std::cout << std::setw(10) << index + 1 << "|";
    std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
    std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
    std::cout << std::setw(10) << (nickName.length() > 10 ? nickName.substr(0, 9) + "." : nickName) << std::endl;
    return ;
}

void    Contact::displayDataExtended() {
    if (firstName.empty() && lastName.empty() && nickName.empty() && phoneNumber.empty() && darkestSecret.empty()) {
		std::cout << "\033[1;31m";
        std::cout << "No data to display" << std::endl << std::endl;
        std::cout << "\033[0m";
        return ;
    }
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl << std::endl;
    return ;
}

bool	Contact::isEmpty() {
    if (firstName.empty() && lastName.empty() && nickName.empty() && phoneNumber.empty() && darkestSecret.empty())
        return (true);
    return (false);
}

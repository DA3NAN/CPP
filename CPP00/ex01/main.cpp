/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:02:14 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/18 21:31:19 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook   phoneBook;
    int         index = 0;

    while (1) {
        std::string command;
        std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            exit(0) ;
        else if (command == "EXIT")
            break ;
        else if (command == "ADD") {
            if (index == 8)
                index = 0;
            phoneBook.addContact(index);
            index++;
        }
        else if (command == "SEARCH")
            phoneBook.serachContact();
        else
            std::cout << "Invalid command" << std::endl << std::endl;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:02:14 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/21 15:25:21 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook   phoneBook;
    int         index = 0;

    while (1) {
        std::string command;
        std::cout << "Available commands: " << "\033[1;32m" << "ADD, SEARCH, EXIT" << std::endl;
        std::cout << "\033[0m";
        std::cout << "Command#> ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            clearerr(stdin), std::cin.clear(), std::cout<<std::endl;
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
        else {
            std::cout << "\033[1;31m";
            std::cout << "Invalid command" << std::endl << std::endl;
            std::cout << "\033[0m";
        }

            //red color text
        // std::cout << "\033[1;31m" << "Hello World" << std::endl;
    }
    return (0);
}
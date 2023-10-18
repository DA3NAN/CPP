/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:47:34 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/17 19:35:36 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		Contact contact[8];

		void addContact(int index) {
			std::cout << "Enter first name: ";
			std::cin >> contact[index].firstName;
			std::cout << "Enter last name: ";
			std::cin >> contact[index].lastName;
			std::cout << "Enter nickname: ";
			std::cin >> contact[index].nickName;
			std::cout << "Enter phone number: ";
			std::cin >> contact[index].phoneNumber;
			std::cout << "Enter darkest secret: ";
			std::cin >> contact[index].darkestSecret;
		}
};

#endif
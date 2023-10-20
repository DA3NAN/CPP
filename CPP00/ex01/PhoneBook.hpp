/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:47:34 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/19 17:47:12 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#define EOF_IGNORE (std::cin.eof() ? (clearerr(stdin), std::cin.clear(), std::cout<<std::endl) : std::cout<<"");

class PhoneBook {
	public:
		Contact contact[8];

		void addContact(int index);
		void serachContact(void);
};

#endif
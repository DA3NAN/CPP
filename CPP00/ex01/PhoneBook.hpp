/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:47:34 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/23 16:12:15 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdio>

#define EOF_IGNORE (std::cin.eof() ? (clearerr(stdin), std::cin.clear(), std::cout<<std::endl) : std::cout<<"");

class PhoneBook {
	private:
		Contact contact[8];
	
	public:
		void addContact(int index);
		void serachContact(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:02:21 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/19 17:31:11 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	public:
		void	setData(std::string firstName, std::string lastName, std::string nickName,
				std::string phoneNumber, std::string darkestSecret);
		void	displayData(int index);
		void	displayDataExtended();
		bool	isEmpty();
};

#endif
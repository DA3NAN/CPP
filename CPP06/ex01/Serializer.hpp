/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:17:16 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/09 15:32:32 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

class Serializer {
	private:
		Serializer();
	public:
		Serializer(Serializer const & src);
		~Serializer();
		Serializer & operator=(Serializer const & src);
		static uintptr_t serialize(Data* data);
		static Data* deserialize(uintptr_t raw);
};

#endif

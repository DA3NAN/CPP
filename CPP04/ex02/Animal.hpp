/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:34:05 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 18:27:06 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class A_Animal {
	protected:
		std::string type;
	public:
		A_Animal();
		A_Animal(A_Animal const & src);
		virtual ~A_Animal();
		A_Animal & operator=(A_Animal const & src);
		std::string getType() const;
		void setType(std::string type);
		virtual void makeSound() const = 0;
};

#endif
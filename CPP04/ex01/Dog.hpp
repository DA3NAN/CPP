/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:37 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/30 22:47:42 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog();
		Dog(Dog const & src);
		~Dog();
		Dog & operator=(Dog const & src);
		void makeSound() const;
};

#endif
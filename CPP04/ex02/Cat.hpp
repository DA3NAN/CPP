/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:25:21 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 17:52:56 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP	
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public A_Animal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const & src);
		~Cat();
		Cat & operator=(Cat const & src);
		void makeSound() const;
};

#endif
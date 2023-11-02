/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:25:21 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/02 13:24:47 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP	
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const & src);
		virtual ~Cat();
		Cat & operator=(Cat const & src);
		void makeSound() const;
};

#endif

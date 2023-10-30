/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:45:20 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/30 17:51:01 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const & src);
		~Brain();
		Brain & operator=(Brain const & src);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif
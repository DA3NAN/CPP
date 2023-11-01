/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:02:26 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/30 18:06:38 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(Brain const & src) {
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const & src) {
	std::cout << "Brain Copy Assignment operator called" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int index, std::string idea) {
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	return (this->ideas[index]);
}

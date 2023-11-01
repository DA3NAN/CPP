/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:58:28 by aait-mal          #+#    #+#             */
/*   Updated: 2023/11/01 18:43:55 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int	N = 10;
	A_Animal *animals[N];
	Dog dog;
	
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		animals[i]->makeSound();
	std::cout << std::endl;
		
	for (int i = 0; i < N; i++)
		delete animals[i];
		
	return (0);
}

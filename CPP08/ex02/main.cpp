/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:01:01 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/14 16:20:56 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "MUTANTSTACK" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "size: " << mstack.size() << std::endl;

	std::cout << std::endl;

	// iterator
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "begin: " << *it << std::endl;
	std::cout << "end: " << *ite << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;

	// const_iterator
	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	++cit;
	--cit;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	// clear the stack
	while (!mstack.empty())
		mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;

	// LIST
	std::cout << std::endl << "LIST" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << "top: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "size: " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << "size: " << list.size() << std::endl;

	std::cout << std::endl;

	// iterator LIST
	std::list<int>::iterator itl = list.begin();
	std::list<int>::iterator itle = list.end();
	std::cout << "begin: " << *itl << std::endl;
	std::cout << "end: " << *itle << std::endl;
	++itl;
	--itl;
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	return 0;
}

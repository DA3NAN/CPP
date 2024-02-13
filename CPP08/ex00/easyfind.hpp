/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:02:38 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/13 15:19:04 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>
# include <set>
# include <map>
# include <functional>

template <typename T>
int easyfind(T &container, int n)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("Not found");
	return *it;
}

// template <typename T>
// int easyfind(T &container, int n)
// {
// 	typename T::const_iterator it;
// 	it = std::find(container.begin(), container.end(), n);
// 	if (it == container.end())
// 		throw std::exception();
// 	return *it;
// }

#endif

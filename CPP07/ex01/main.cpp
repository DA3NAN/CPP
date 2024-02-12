/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:07:48 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/10 19:17:44 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void upper(std::string &s) {
	for (size_t i = 0; i < s.length(); i++) {
		s[i] = std::toupper(s[i]);
	}
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	::iter(arr, 5, ::increment);
	::iter(arr, 5, ::print);

	std::string arr2[] = {"Hello", "World", "Fluff", "Dash"};
	::iter(arr2, 4, upper);
	::iter(arr2, 4, ::print);

	return 0;
}

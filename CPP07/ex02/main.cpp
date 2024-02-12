/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:35:34 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/12 15:32:40 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> arr(5);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	try
	{
		for (unsigned int i = 0; i < 6; i++)
			std::cout << arr[i] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

    Array<int> arr2(arr);
    Array<int> arr3;
    arr3 = arr2;

    try {
        for (unsigned int i = 0; i < 5; i++)
            std::cout << arr2[i] << std::endl;
        std::cout << arr3[-2] << std::endl;
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}

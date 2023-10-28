/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:08:41 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/28 17:08:50 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int		main(void) {
	Point const	a(0.0f, 0.0f);
	Point const	b(10.0f, 0.0f);
	Point const	c(0.0f, 10.0f);
	Point const	point(5.0f, 5.0f);

	std::cout << "a = " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "b = " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "c = " << c.getX() << ", " << c.getY() << std::endl;
	std::cout << "point = " << point.getX() << ", " << point.getY() << std::endl;
	std::cout << "bsp(a, b, c, point) = " << bsp(a, b, c, point) << std::endl;
	return (0);
}

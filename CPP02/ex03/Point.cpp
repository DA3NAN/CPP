/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:07:28 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/28 17:08:06 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
}

Point::Point(const float x, const float y) : x(x), y(y) {
}

Point::Point(const Point &point) : x(point.x), y(point.y) {
}

Point::~Point(void) {
}

Point	&Point::operator=(const Point &point) {
	if (this != &point) {
		*this = point;
	}
	return (*this);
}

Fixed	Point::getX(void) const {
	return (this->x);
}

Fixed	Point::getY(void) const {
	return (this->y);
}

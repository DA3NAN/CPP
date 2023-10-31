/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:48:49 by aait-mal          #+#    #+#             */
/*   Updated: 2023/10/31 23:12:31 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void) : value(0) {
}

Fixed::Fixed(const int value) {
	this->value = value << this->bits;
}

Fixed::Fixed(const float value) {
	this->value = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::~Fixed(void) {
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed) {
		this->value = fixed.getRawBits();
    }
	return (*this);
}

int		Fixed::getRawBits(void) const {
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->value / (float)(1 << this->bits));
}

int		Fixed::toInt(void) const {
	return (this->value >> this->bits);
}

bool	Fixed::operator>(const Fixed &fixed) const {
	return (this->value > fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixed) const {
	return (this->value < fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed) const {
	return (this->value >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed) const {
	return (this->value <= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed) const {
	return (this->value == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed) const {
	return (this->value != fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &fixed) const {
	Fixed res;

	res.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &fixed) const {
	Fixed res;

	res.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &fixed) const {
	Fixed res;

	res.setRawBits((static_cast<long long>(this->getRawBits()) * fixed.getRawBits()) >> bits);
	return res;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    Fixed res;

    res.setRawBits((static_cast<long long>(this->getRawBits()) << bits) / fixed.getRawBits());
    return res;
}

Fixed	&Fixed::operator++(void) {
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--(void) {
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

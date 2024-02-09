/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:24:44 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/09 15:25:22 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const & src) {
	*this = src;
}

Serializer::~Serializer() {}

Serializer & Serializer::operator=(Serializer const & src) {
	(void)src;
	return *this;
}

uintptr_t Serializer::serialize(Data* data) {
	uintptr_t raw = reinterpret_cast<uintptr_t>(data);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data *data = reinterpret_cast<Data*>(raw);
	return data;
}

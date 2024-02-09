/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:32:20 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/09 15:38:57 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data data;

	data.s1 = "Bonjour";
	data.n = 1337;
	data.s2 = "Le Monde hh!";

	std::cout << "Data: " << data.s1 << " " << data.n << " " << data.s2 << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Raw(unitptr_t): " << raw << std::endl;

	Data *data2 = Serializer::deserialize(raw);
	std::cout << "DeSerialized Data: " << data2->s1 << " " << data2->n << " " << data2->s2 << std::endl;

	return (0);
}

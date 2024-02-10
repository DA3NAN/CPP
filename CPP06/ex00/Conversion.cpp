/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:57:20 by adnane            #+#    #+#             */
/*   Updated: 2024/02/10 00:55:20 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int stringToInt(const std::string& str) {
    char* endptr;
    long int result = strtol(str.c_str(), &endptr, 10);

    if (result < INT_MIN || result > INT_MAX) {
        throw std::runtime_error("impossible");
    }

    return static_cast<int>(result);
}

float stringToFloat(const std::string& str) {
    char* endptr;
	std::string trimmedString = str;

	if (trimmedString[trimmedString.length() - 1] == 'f') {
		trimmedString = trimmedString.substr(0, trimmedString.length() - 1);
	}

    float result = strtof(trimmedString.c_str(), &endptr);

    if (endptr == trimmedString.c_str() || *endptr != '\0') {
        throw std::runtime_error("impossible");
    }

    if (result == HUGE_VALF || result == -HUGE_VALF) {
        throw std::runtime_error("impossible");
    }

    return result;
}

double stringToDouble(const std::string& str) {
    char* endptr;
	std::string trimmedString = str;

	if (trimmedString[trimmedString.length() - 1] == 'f') {
		trimmedString = trimmedString.substr(0, trimmedString.length() - 1);
	}

    double result = strtod(trimmedString.c_str(), &endptr);

    if (endptr == trimmedString.c_str() || *endptr != '\0') {
        throw std::runtime_error("impossible");
    }

    if (result == HUGE_VAL || result == -HUGE_VAL) {
        throw std::runtime_error("impossible");
    }

    return result;
}

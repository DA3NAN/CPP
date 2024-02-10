/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:57:20 by adnane            #+#    #+#             */
/*   Updated: 2024/02/10 14:28:00 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

char stringToChar(const std::string& str) {
    int result = stringToInt(str);

    if (result < CHAR_MIN || result > CHAR_MAX) {
        throw std::runtime_error("impossible");
    } else if (!isprint(result)) {
        throw std::runtime_error("Non displayable");
    }

    return static_cast<char>(result);
}

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
    std::string str2 = str;

	trimLastF(str2);
    float result = strtof(str2.c_str(), &endptr);

    if (endptr == str2.c_str() || *endptr != '\0') {
        throw std::runtime_error("impossible");
    }

    if (result == HUGE_VALF || result == -HUGE_VALF) {
        throw std::runtime_error("impossible");
    }

    return result;
}

double stringToDouble(const std::string& str) {
    char* endptr;
    std::string str2 = str;

	trimLastF(str2);
    double result = strtod(str2.c_str(), &endptr);

    if (endptr == str2.c_str() || *endptr != '\0') {
        throw std::runtime_error("impossible");
    }

    if (result == HUGE_VAL || result == -HUGE_VAL) {
        throw std::runtime_error("impossible");
    }

    return result;
}

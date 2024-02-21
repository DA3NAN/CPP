/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PaseFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:59:53 by adnane            #+#    #+#             */
/*   Updated: 2024/02/21 19:22:01 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int parseDateWhitespaces(const std::string& str) {
    int count = 0;

    if (std::isspace(str[0]))
        return 1;
    for (size_t i = str.size() - 1; i > 0; i--) {
        if (std::isspace(str[i]))
            count++;
        else
            break;
    }
    if (count != 1)
        return 1;
    return 0;
}

int parseValueWhitespaces(const std::string& str) {
    int count = 0;

    for (size_t i = 0; i < str.size(); i++) {
        if (std::isspace(str[i]))
            count++;
        else
            break;
    }

    if (count != 1)
        return 1;
    return 0;
}

void removeWhitespace(std::string& str) {
    std::string argument(str);
    size_t start = 0;
    size_t end = argument.size();

    // Skip leading whitespaces
    while (start < end && std::isspace(argument[start]))
        start++;

    // Skip trailing whitespaces
    while (end > start && std::isspace(argument[end - 1]))
        end--;

    std::string token;
    token = argument.substr(start, end - start);
    str = token;
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1)
        return false;

    // Check days based on the month
    if (month == 2) { // February
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear) {
            if (day > 29)
                return false; // Leap year: February can have up to 29 days
        } else {
            if (day > 28)
                return false; // Non-leap year: February has 28 days, example 1900 or 2018
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false; // April, June, September, November have 30 days
    } else {
        if (day > 31)
            return false; // All other months have 31 days
    }

    return true;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PaseFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:59:53 by adnane            #+#    #+#             */
/*   Updated: 2024/02/21 15:25:14 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void removeWhitespace(std::string& str) {
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PaseFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:59:53 by adnane            #+#    #+#             */
/*   Updated: 2024/02/17 02:53:28 by adnane           ###   ########.fr       */
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

    if (year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

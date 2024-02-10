/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:53:49 by adnane            #+#    #+#             */
/*   Updated: 2024/02/10 00:33:56 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.hpp"

bool isValid(std::string const & str) {
	int	pointCount = 0;

	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	if (isOctalLiteral(str))
		return false;
	if (str.length() >= 1 && (isdigit(str[0]) || str[0] == '-' || str[0] == '+')) {
		size_t i = 0;
		if (str[i] == '-' || str[i] == '+')
			i++;

		for (size_t j = i; j < str.length(); j++) {
			if (str[j] == '.')
				pointCount++;
		}
		if (pointCount > 1)
			return false;

		for (; i < str.length(); i++) {
			if (isdigit(str[i])
				|| (str[i] == '.'
					&& str[i - 1] && isdigit(str[i - 1])
					&& str[i + 1] != 'f'
					&& i != str.length() - 1)
				|| (str[i] == 'f' && i == str.length() - 1)
				)
				continue;
			else
				return false;
		}
		return true;
	}
	return false;
}

bool specialCase(std::string const & str) {
	if (str.length() == 1 && !isdigit(str[0])) {
		std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
		return true;
	} else if (str == "-inff" || str == "+inff" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		return true;
	} else if (str == "-inf" || str == "+inf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return true;
	}
	return false;
}

bool isOctalLiteral(const std::string& str) {
    if (str.empty() || str[0] != '0' || (str.length() == 1 && str[0] == '0')) {
        return false;
    }

    std::istringstream iss(str);
    int num;
    iss >> std::oct >> num;

    return !iss.fail() && iss.eof();
}

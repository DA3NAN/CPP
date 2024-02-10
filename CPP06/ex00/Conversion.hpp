/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:57:01 by adnane            #+#    #+#             */
/*   Updated: 2024/02/10 14:24:55 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include "ScalarConverter.hpp"
# include "Parsing.hpp"

char stringToChar(const std::string& str);
int stringToInt(const std::string& str);
float stringToFloat(const std::string& str);
double stringToDouble(const std::string& str);

#endif

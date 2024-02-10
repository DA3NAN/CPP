/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:54 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/10 00:23:49 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <cmath>

class ScalarConverter {
	private:
		ScalarConverter();
	public:
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & src);
		static void convert(std::string const & str);
};

void printChar(char c);
void printInt(int i);
void printFloat(float f);
void printDouble(double d);

#endif

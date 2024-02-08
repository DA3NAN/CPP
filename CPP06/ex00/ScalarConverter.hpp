/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:02:54 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/08 19:00:22 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter {
	private:
		ScalarConverter();
	public:
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & src);
		static void convert(std::string const & str);

		class NotValidException: public std::exception {
			public:
				const char* what() const throw();
		};

		class ImpossibleException: public std::exception {
			public:
				const char* what() const throw();
		};

		class NonDisplayableException: public std::exception {
			public:
				const char* what() const throw();
		};
};

bool isValid(std::string const & str);
void printChar(char c);
void printInt(int i);
void printFloat(float f);
void printDouble(double d);
bool specialCase(std::string const & str);

#endif

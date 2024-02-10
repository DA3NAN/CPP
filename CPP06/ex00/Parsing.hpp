/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:54:12 by adnane            #+#    #+#             */
/*   Updated: 2024/02/10 14:16:09 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
# define PARSING_HPP

# include "ScalarConverter.hpp"

bool isValid(std::string const & str);
bool specialCase(std::string const & str);
bool isOctalLiteral(const std::string& str);
void trimLastF(std::string& str);

#endif

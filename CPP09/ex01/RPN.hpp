/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:47:19 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/19 22:07:05 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>

class RPN {
	private:
		std::stack<double> _stack;
		std::string _input;
	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();
		void calculate();
		void printStack();
		void printResult();
};

bool isNumber(const std::string &s);
bool isEmptyOrWhitespace(const std::string& _input);

#endif

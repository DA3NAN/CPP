/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:51:42 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/17 16:25:23 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input) : _input(input) {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src) {
		_input = src._input;
		_stack = src._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::calculate() {
	std::istringstream iss(_input);
	std::string token;
	double num;

	//check if input is empty or just whitespaces
	if (_input.empty() || std::all_of(_input.begin(), _input.end(), isspace)) {
		throw std::runtime_error("Empty input");
	}

	while (iss >> token) {
		if (token.length() == 1 && !isdigit(token[0])) {
			if (strchr("+-*/^", token[0]) == NULL) {
				throw std::runtime_error("Invalid operator");
			} else if (_stack.size() < 2) {
				throw std::runtime_error("Not enough operands");
			}
			double second = _stack.top();
			_stack.pop();
			double first = _stack.top();
			_stack.pop();
			if (token == "+") {
				_stack.push(first + second);
			} else if (token == "-") {
				_stack.push(first - second);
			} else if (token == "*") {
				_stack.push(first * second);
			} else if (token == "/") {
				if (second == 0)
					throw std::runtime_error("Division by zero");
				_stack.push(first / second);
			} else if (token == "^") {
				_stack.push(pow(first, second));
			}
		} else {
            if (std::istringstream(token) >> num && num == (int)num && num >= 0 && num <= 9 && isNumber(token)) {
                _stack.push(num);
            } else {
                throw std::runtime_error("Invalid number");
            }
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("Too many operands");
	}
}

void RPN::printStack() {
	std::stack<double> tmp = _stack;
	while (!tmp.empty()) {
		std::cout << tmp.top() << " ";
		tmp.pop();
	}
	std::cout << std::endl;
}

void RPN::printResult() {
	std::cout << static_cast<int>(_stack.top()) << std::endl;
}

bool isNumber(const std::string &s) {
	return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

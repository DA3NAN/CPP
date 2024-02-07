/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:49:02 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/07 15:37:09 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _executeGrade;
	public:
		AForm();
		AForm(std::string const &name, int signGrade, int executeGrade);
		AForm(AForm const & src);
		virtual ~AForm();
		AForm & operator=(AForm const & src);
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(Bureaucrat const & b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
		class FormNotSignedException: public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & os, AForm const & f);

#endif

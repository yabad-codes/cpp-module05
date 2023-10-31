/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:47:21 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 14:57:56 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP
# include <iostream>

class Form {
	private:
		std::string const	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		Form();
		Form(std::string const, const int, const int);
		Form(const Form&);
		~Form();

		Form&	operator=(const Form&);

		std::string const	getName() const;
		bool	isFormSigned() const;
		const int	gradeToSign() const;
		const int	gradeToExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream&, Form&);

#endif
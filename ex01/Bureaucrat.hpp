/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:22:31 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 15:44:11 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define MAX_GRADE 1
# define MIN_GRADE 150

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const, int);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();
		
		Bureaucrat&	operator=(const Bureaucrat&);
		
		std::string const	getName() const;
		int	getGrade() const;
		void	increment();
		void	decrement();
		void	signForm(Form&);
		
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream&, Bureaucrat&);

#endif
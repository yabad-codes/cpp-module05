/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:47:21 by yabad             #+#    #+#             */
/*   Updated: 2023/11/06 16:37:29 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP

# define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		AForm();
		AForm(std::string const, const int, const int);
		AForm(const AForm&);
		virtual ~AForm();

		AForm&	operator=(const AForm&);

		std::string const	getName() const;
		bool	isFormSigned() const;
		int	gradeRequiredToSign() const;
		int	gradeRequiredToExecute() const;
		void	beSigned(Bureaucrat&);
		void	execute(Bureaucrat const& executor) const;
		virtual void	executeAction() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		
		class FormAlreadySignedException : public std::exception {
			public:
				const char* what() const throw();
		};
		
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream&, AForm&);

#endif
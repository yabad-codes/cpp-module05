/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:20:55 by yabad             #+#    #+#             */
/*   Updated: 2023/11/06 15:34:33 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	std::cout << "*------------------ Start shrubbery testing block ------------------*" << std::endl;
	{
		Bureaucrat	b1("Cap", 69);
		Bureaucrat	b2("Spiderman", 130);
		ShrubberyCreationForm	form;

		try {
			form.beSigned(b1);
			form.execute(b2);
		} catch(std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "*------------------ End shrubbery testing block ------------------*" << std::endl << std::endl;
	std::cout << "*------------------ Start robotomy testing block ------------------*" << std::endl;
	{
		Bureaucrat	b1("Cap", 69);
		Bureaucrat	b2("Spiderman", 45);
		RobotomyRequestForm	form;

		try {
			form.beSigned(b1);
			form.execute(b2);
		} catch(std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "*------------------ End robotomy testing block ------------------*" << std::endl << std::endl;
	std::cout << "*------------------ Start presedential pardon testing block ------------------*" << std::endl;
	{
		Bureaucrat	b1("Cap", 3);
		Bureaucrat	b2("Spiderman", 24);
		PresidentialPardonForm	form;

		try {
			b2.signForm(form);
			b1.executeForm(form);
		} catch(std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "*------------------ End presidential pardon testing block ------------------*" << std::endl << std::endl;
}
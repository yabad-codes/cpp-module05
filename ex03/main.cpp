/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:20:55 by yabad             #+#    #+#             */
/*   Updated: 2023/11/06 16:50:05 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	std::cout << "*------------------ Start test 1 ------------------*" << std::endl;
	{
		Intern	slave;
		AForm*	form;
		Bureaucrat	b("peter parker", 2);
		
		form = slave.makeForm("shrubbery creation", "yabad");
		try {
			form->beSigned(b);
			form->execute(b);
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		delete form;
	}
	std::cout << "*------------------ End test 1 ------------------*" << std::endl << std::endl;
	std::cout << "*------------------ Start test 2 ------------------*" << std::endl;
	{
		Intern	slave;
		AForm*	form;
		Bureaucrat	b("peter parker", 2);
		
		form = slave.makeForm("69", "yabad");
		delete form;
	}
	std::cout << "*------------------ End test 2 ------------------*" << std::endl << std::endl;
	std::cout << "*------------------ Start test 3 ------------------*" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	std::cout << "*------------------ End test 3 ------------------*" << std::endl << std::endl;
}
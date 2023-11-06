/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:43:43 by yabad             #+#    #+#             */
/*   Updated: 2023/11/06 16:35:38 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Default constructor called for Intern." << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Copy constructor called for Intern." << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << "Destructor called for Intern." << std::endl;
}

Intern&	Intern::operator=(const Intern& other) {
	(void)other;
	return (*this);
}

AForm*	Intern::createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string formName, std::string target) {
	std::string	forms[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	
	AForm*	(Intern::*func[3])(std::string) = { &Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm };
	for (int i = 0; i < 3; i++) {
		if (forms[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*func[i])(target);
		}
	}
	std::cerr << "Intern can't create the provided form." << std::endl;
	return (NULL);
}
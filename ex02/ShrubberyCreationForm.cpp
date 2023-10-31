/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:32:44 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 19:38:00 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("home") {
	std::cout << "Shrubbery default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target) {
	std::cout << "Shrubbery constructor with params called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery destructor called." << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Shrubbery copy assignment operator called." << std::endl;
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}
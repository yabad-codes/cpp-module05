/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:32:44 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 20:38:22 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("home") {
	std::cout << "Shrubbery default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target(target) {
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

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream	file;
	file.open(this->target + "_shrubbery");
	std::string	tree = 
	"     *\n"
	"    ***\n"
	"   *****\n"
	"  *******\n"
	" *********\n"
	"***********\n"
	"     |\n"
	"     |";
	if (file.is_open()) {
		file << tree << std::endl;
		file.close();
	}
}
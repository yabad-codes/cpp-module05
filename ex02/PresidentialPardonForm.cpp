/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:11:30 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 22:20:01 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), target("Angelo") {
	std::cout << "Presidential form default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), target(target) {
	std::cout << "Presidential form constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
	std::cout << "Presidential Form copy constructor called." << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Form destructor called." << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Presidential Pardon copy assignment operator called." << std::endl;
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

void	PresidentialPardonForm::executeAction() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
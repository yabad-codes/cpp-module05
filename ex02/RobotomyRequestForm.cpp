/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:40:32 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 22:06:16 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("rick") {
	std::cout << "Robotomy default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), target(target) {
	std::cout << "Robotomy constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
	std::cout << "Robotomy copy constructor called." << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy destructor called." << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Robotomy copy assignment operator called." << std::endl;
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

void	RobotomyRequestForm::executeAction() const {
	std::srand(std::time(NULL));
	int	random_number = std::rand();
	if (random_number % 2) {
		std::cout << "Robotomy failed." << std::endl;
		return ;
	}
	std::cout << this->target << " has been robotomized successfuly." << std::endl;
	return;
}
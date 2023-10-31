/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:54:56 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 15:47:55 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Lucy"), grade(150) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
	std::cout << "A Bureaucrat constructor with params called." << std::endl;
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << "Bureaucrat's copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat's destructor called." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat's copy assignment operator called." << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

std::string const	Bureaucrat::getName() const {
	return (this->name);
}

int	Bureaucrat::getGrade() const {
	return (this->grade);
}

void	Bureaucrat::increment() {
	int	newPotentialGrade = this->grade - 1;
	if (newPotentialGrade < MAX_GRADE)
		throw GradeTooHighException();
	this->grade = newPotentialGrade;
}

void	Bureaucrat::decrement() {
	int	newPotentialGrade = this->grade + 1;
	if (newPotentialGrade > MIN_GRADE)
		throw GradeTooLowException();
	this->grade = newPotentialGrade;
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	} catch(std::exception& e) {
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat& bureaucrat) {
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (COUT);
}
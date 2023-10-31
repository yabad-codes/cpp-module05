/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:58:22 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 16:11:36 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("random_form"), gradeToSign(5), gradeToExecute(2) {
	this->isSigned = false;
	std::cout << "Form created with default constructor." << std::endl;
}

Form::Form(std::string const name, const int signGrade, const int executeGrade) : name(name), gradeToSign(signGrade), gradeToExecute(executeGrade) {
	this->isSigned = false;
	std::cout << "Form created with a constructor with params." << std::endl;
}

Form::Form(const Form& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	this->isSigned = other.isSigned;
	std::cout << "Form created with copy constructor." << std::endl;
}

Form::~Form() {
	std::cout << "Form destructed." << std::endl;
}

Form&	Form::operator=(const Form& other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

std::string const	Form::getName() const {
	return (this->name);
}

bool Form::isFormSigned() const {
	return (this->isSigned);
}

int	Form::gradeRequiredToSign() const {
	return (this->gradeToSign);
}

int	Form::gradeRequiredToExecute() const {
	return (this->gradeToExecute);
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign && this->isSigned == false) {
		this->isSigned = true;
		std::cout << this->name << " signed by " << bureaucrat;
	}
	else if (this->isSigned == true)
		throw FormAlreadySignedException();
	else
		throw Form::GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char*	Form::FormAlreadySignedException::what() const throw() {
	return ("Form already signed");
}

std::ostream&	operator<<(std::ostream& COUT, Form& form) {
	std::cout << "Form name : " << form.getName() << std::endl;
	std::cout << "Is Form signed : " << (form.isFormSigned() ? "Yes" : "No") << std::endl;
	std::cout << "Grade to sign this form : " << form.gradeRequiredToSign() << std::endl;
	std::cout << "Grade to execute this form : " << form.gradeRequiredToExecute() << std::endl;
	return (COUT);
}
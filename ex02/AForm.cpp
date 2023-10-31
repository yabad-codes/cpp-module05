/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:58:22 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 20:01:36 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("random_form"), gradeToSign(5), gradeToExecute(2) {
	this->isSigned = false;
	std::cout << "Form created with default constructor." << std::endl;
}

AForm::AForm(std::string const name, const int signGrade, const int executeGrade) : name(name), gradeToSign(signGrade), gradeToExecute(executeGrade) {
	this->isSigned = false;
	std::cout << "Form created with a constructor with params." << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	this->isSigned = other.isSigned;
	std::cout << "Form created with copy constructor." << std::endl;
}

AForm::~AForm() {
	std::cout << "Form destructed." << std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

std::string const	AForm::getName() const {
	return (this->name);
}

bool AForm::isFormSigned() const {
	return (this->isSigned);
}

int	AForm::gradeRequiredToSign() const {
	return (this->gradeToSign);
}

int	AForm::gradeRequiredToExecute() const {
	return (this->gradeToExecute);
}

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign && this->isSigned == false) {
		this->isSigned = true;
		std::cout << this->name << " signed by " << bureaucrat;
	}
	else if (this->isSigned == true)
		throw FormAlreadySignedException();
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!(this->isSigned && executor.getGrade() <= this->gradeToExecute)) {
		if (!this->isSigned)
			throw FormNotSignedException();
		throw GradeTooLowException();
	}
	executeAction();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char*	AForm::FormAlreadySignedException::what() const throw() {
	return ("Form already signed");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
}

std::ostream&	operator<<(std::ostream& COUT, AForm& form) {
	std::cout << "Form name : " << form.getName() << std::endl;
	std::cout << "Is Form signed : " << (form.isFormSigned() ? "Yes" : "No") << std::endl;
	std::cout << "Grade to sign this form : " << form.gradeRequiredToSign() << std::endl;
	std::cout << "Grade to execute this form : " << form.gradeRequiredToExecute() << std::endl;
	return (COUT);
}
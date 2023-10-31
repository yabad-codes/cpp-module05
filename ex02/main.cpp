/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:20:55 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 20:16:24 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:20:55 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 16:11:09 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	b1("Cap", 6);
	Form		form("Avengers application form", 5, 2);
	
	std::cout << b1 << form;
	try {
		form.beSigned(b1);
		b1.signForm(form);
		printf("Should not be printed on the screen");
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
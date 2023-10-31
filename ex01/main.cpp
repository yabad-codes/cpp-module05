/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:20:55 by yabad             #+#    #+#             */
/*   Updated: 2023/10/31 14:27:08 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	b1("Captain America", 3);
	Bureaucrat	b2(b1);
	Bureaucrat	b3;
	
	try {
		b2 = b3;
		b1.increment();
		std::cout << b1;
		b1.increment();
		std::cout << b1;
		b1.increment();
		std::cout << b1;
		b3.decrement();
	} catch(std::exception& e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return (0);
}
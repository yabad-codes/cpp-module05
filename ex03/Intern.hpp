/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:43:41 by yabad             #+#    #+#             */
/*   Updated: 2023/11/06 15:54:52 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern&);
		~Intern();
		
		Intern& operator=(const Intern&);

		AForm*	createShrubberyCreationForm(std::string);
		AForm*	createRobotomyRequestForm(std::string);
		AForm*	createPresidentialPardonForm(std::string);
		AForm*	makeForm(std::string, std::string);
};

#endif
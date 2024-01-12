/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:54:59 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/10 10:58:54 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
	{
		private :
			class	printMsgError : public std::exception
			{
				public :
					const char	*what() const throw();
			};

		public :
			Intern();
			Intern(const Intern& copy);
			~Intern();
			
			Intern& operator=(const Intern& assign);

            AForm*  makeForm(std::string name, std::string target);
	};

#endif

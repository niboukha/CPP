/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:55:02 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/10 11:00:58 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern& copy)
{
	this->operator=(copy);	
}

Intern::~Intern()
{
	
}

Intern& Intern::operator=(const Intern& assign)
{
	(void)assign;
	return (*this);
}

AForm*  Intern::makeForm(std::string name, std::string target)
{
	std::string	arr[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	try
	{
		int	i = 0;

		for (;i < 3; i++)
		{	if (!name.compare(arr[i])) break;	}
		
		switch(i)
		{
			case 0:
				std::cout << "Intern creates " << name << std::endl;
				return (new PresidentialPardonForm(target));
			case 1:
				std::cout << "Intern creates " << name << std::endl;
				return (new RobotomyRequestForm(target));
			case 2:
				std::cout << "Intern creates " << name << std::endl;
				return (new ShrubberyCreationForm(target));
			default : 
				throw printMsgError();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << name << std::endl;
	}
	return (NULL);
}

const char*	Intern::printMsgError::what() const throw()
{
	return ("Intern Can't creates a ");
}

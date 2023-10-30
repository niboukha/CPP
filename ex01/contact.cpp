/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:01:15 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/30 13:56:19 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::trim_string(std::string &name)
{
	std::size_t	first;
	std::size_t	last;

	first = name.find_first_not_of(" \f\n\r\t\v");
	last = name.find_last_not_of(" \f\n\r\t\v");
	if (first == std::string::npos || last == std::string::npos)
	{
		first = 0;
		last = -1;
	}
	name = name.substr(first, last - first + 1);
}

void	Contact::check_input(std::string &name)
{
	trim_string(name);
	std::replace(name.begin(), name.end(), '\t', ' ');
	if (name.length() > 10)
	{
		name = name.substr(0, 9);
		name.append(".");
	}
}

std::string	Contact::getFirst_name()
{
	return (first_name); 
}

void	Contact::setFirst_name(std::string &name)
{
	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "First Name    : ";
		std::getline(std::cin, name);
		trim_string(name);
		if (!name.empty())
		{
			first_name = name;
			break;
		}
	}
}

std::string	Contact::getLast_name()
{
	return (last_name); 
}

void	Contact::setLast_name(std::string &name)
{
	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "Last Name     : ";
		std::getline(std::cin, name);
		trim_string(name);
		if (!name.empty())
		{
			last_name = name;
			break;
		}
	}
}

std::string	Contact::getNickname()
{
	return (nickname);
}

void	Contact::setNickname(std::string &name)
{
	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "Nickname      : ";
		std::getline(std::cin, name);
		trim_string(name);
		if (!name.empty())
		{
			nickname = name;		
			break;
		}
	}
}

std::string	Contact::getPhone_num()
{
	return (phone_num);
}

void	Contact::setPhone_num(std::string &name)
{
	std::size_t	first;
	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "Phone Number  : ";
		std::getline(std::cin, name);
		trim_string(name);
		first = name.find_first_not_of("0123456789 \t\n\r\v");
		if (!first || name.empty())
			std::cout << red << "phone number should have only digits" << std::endl;
		else
		{
			phone_num = name;
			break;
		}
		std::cout << reset;
	}
}

std::string	Contact::getDarkest_secret()
{
	return (darkest_secret);
}

void	Contact::setDarkest_secret(std::string &name)
{
	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, name);
		trim_string(name);
		if (!name.empty())
		{
			darkest_secret = name;
			break;
		}
	}
}

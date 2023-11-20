/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:01:15 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/20 13:21:58 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

const std::string&	Contact::getFirstName() const
{
	return (firstName); 
}

bool	Contact::setFirstName()
{
	std::string input;

	while (1)
	{
		std::cout << "First Name    : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (false);
		PhoneBook::trimString(input);
		if (!input.empty())
		{
			firstName = input;
			return (true);
		}
	}
}

const std::string&	Contact::getLastName() const
{
	return (lastName); 
}

bool	Contact::setLastName()
{
	std::string input;

	while (1)
	{
		std::cout << "Last Name     : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (false);
		PhoneBook::trimString(input);
		if (!input.empty())
		{
			lastName = input;
			return (true);
		}
	}
}

const std::string&	Contact::getNickname() const
{
	return (nickname);
}

bool	Contact::setNickname()
{
	std::string input;

	while (1)
	{
		std::cout << "Nickname      : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (false);
		PhoneBook::trimString(input);
		if (!input.empty())
		{
			nickname = input;		
			return (true);
		}
	}
}

const std::string&	Contact::getPhoneNum() const
{
	return (phoneNum);
}

bool	Contact::setPhoneNum()
{
	std::string number;
	std::size_t	first;

	while (1)
	{
		std::cout << "Phone Number  : ";
		std::getline(std::cin, number);
		if (std::cin.eof())
			return (false);
		PhoneBook::trimString(number);
		first = number.find_first_not_of("0123456789 \t\n\r\v");
		if (!first || number.empty())
			std::cout << red << "phone number should have only digits" << std::endl;
		else
		{
			phoneNum = number;
			return (true);
		}
		std::cout << reset;
	}
}

const std::string&	Contact::getDarkestSecret() const
{
	return (darkestSecret);
}

bool	Contact::setDarkestSecret()
{
	std::string input;
	while (1)
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (false);
		PhoneBook::trimString(input);
		if (!input.empty())
		{
			darkestSecret = input;
			return (true);
		}
	}
}

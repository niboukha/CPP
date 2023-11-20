/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:01:29 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/20 13:20:54 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	PhoneBook::trimString(std::string &input)
{
	std::size_t	first;
	std::size_t	last;

	first = input.find_first_not_of(" \f\n\r\t\v");
	last = input.find_last_not_of(" \f\n\r\t\v");
	if (first == std::string::npos || last == std::string::npos)
	{
		first = 0;
		last = -1;
	}
	input = input.substr(first, last - first + 1);
}

void	PhoneBook::checkInput(std::string &input)
{
	trimString(input);
	std::replace(input.begin(), input.end(), '\t', ' ');
	if (input.length() > 10)
	{
		input = input.substr(0, 9);
		input.append(".");
	}
}

int		PhoneBook::getIndex()
{
	return (index);
}

void	PhoneBook::setIndex(int i)
{
	index = i;
}

void	PhoneBook::writeString(std::string const &input, const char *color)
{
	unsigned long i;

	i = 0;
	while (i < input.length())
	{
		std::cout << color << input[i] << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		i++;
	}
	std::cout << std::endl;
}

bool	PhoneBook::valideCmd(std::string &input, std::string cmd)
{
	if (!input.compare(cmd))
		return (true);
	return (false);
}

void	PhoneBook::contactInformation(int index)
{
	std::string	input;
	int			i;
	
	i = index + 1;
	std::cout << green << "Enter an index to display the contact informations : " << reset << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		PhoneBook::exitMessage("Abborting !!");
	if (input.empty())
		return ;
	if (!input.find_first_not_of("0123456789"))
	{
		std::cout << red << "Index should have only digits" << std::endl;
		std::cout << reset;
		return ;
	}
	else if (input.length() == 1)
		i = input[0] - 48;
	if (i - 1 < index && i > 0)
	{
		std::cout << "First Name    : " << arrContacts[i - 1].getFirstName() << std::endl;
		std::cout << "Last Name     : " << arrContacts[i - 1].getLastName() << std::endl;
		std::cout << "Nickname      : " << arrContacts[i - 1].getNickname() << std::endl;
		std::cout << "Phone Number  : " << arrContacts[i - 1].getPhoneNum() << std::endl;
		std::cout << "Darkest Secret: " << arrContacts[i - 1].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << red << "Invalid index!!" << std::endl;
		std::cout << reset;
		return ;
	}
}

void	PhoneBook::search(int index)
{
	PhoneBook	contact;
	std::string	fname;
	std::string	lname;
	std::string	nname;
	int			i;

	std::cout << "|^^^^^^^^^^" << "|^^^^^^^^^^" << "|^^^^^^^^^^" << "|^^^^^^^^^^|" << std::endl;
	std::cout << "|     Index" << "|First name" << "| Last name" << "|  Nickname|" << std::endl;
	std::cout << "|----------" << "|----------" << "|----------" << "|----------|" << std::endl;
	i = 0;
	while (i < index)
	{
		fname = arrContacts[i].getFirstName();
		checkInput(fname);
		lname = arrContacts[i].getLastName();
		checkInput(lname);
		nname = arrContacts[i].getNickname();
		checkInput(nname);
		std::cout << "|" << std::flush;
		std::cout << std::setw(10) << i + 1 << "|" 
					<< std::setw(10) << fname << "|" 
					<< std::setw(10) << lname << "|" 
					<< std::setw(10) << nname << "|" 
					<< std::endl;
		std::cout << "|----------" << "|----------" << "|----------" << "|----------|" << std::endl;
		i++;
	}
	contactInformation(index);
}

bool	PhoneBook::addContact(int index)
{
	writeString(" The Information Of The New Contact", green);
	std::cout << reset;
	return (
		arrContacts[index % 8].setFirstName() and
		arrContacts[index % 8].setLastName() and
		arrContacts[index % 8].setNickname() and
		arrContacts[index % 8].setPhoneNum() and
		arrContacts[index % 8].setDarkestSecret() );
}

void	PhoneBook::exitMessage (std::string message)
{
	std::cout << std::endl << red << message << std::endl;	
	exit(0);
}


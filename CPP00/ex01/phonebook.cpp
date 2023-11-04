/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:01:29 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/30 14:31:18 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int		PhoneBook::getIndex()
{
	return (index);
}

void	PhoneBook::setIndex(int i)
{
	index = i;
}

void	PhoneBook::write_string(std::string const &name, const char *color)
{
	unsigned long i;

	i = 0;
	while (i < name.length())
	{
		std::cout << color << name[i] << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		i++;
	}
	std::cout << std::endl;
}

bool	PhoneBook::valide_cmd(std::string &name, std::string cmd)
{
	if (!name.compare(cmd))
		return (true);
	return (false);
}

void	PhoneBook::contact_information(int index)
{
	std::string	name;
	int			i;
	int			j;
	int			flag;
	
	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cout << green << "Enter an index to display the contact informations : " << reset << std::endl;
		std::getline(std::cin, name);
		if (name.empty())
			break;
		if (!name.find_first_not_of("12345678 \t\n\r\v"))
		{
			std::cout << red << "Index should have only digits" << std::endl;
			std::cout << reset;
			continue;
		}
		else
			i = std::stoi(name);
		j = 0;
		flag = 0;
		while (j < index)
		{
			if (i - 1 == j)
			{
				flag = 1;
				std::cout << "First Name    : " << arr_contacts[j].getFirst_name() << std::endl;
				std::cout << "Last Name     : " << arr_contacts[j].getLast_name() << std::endl;
				std::cout << "Nickname      : " << arr_contacts[j].getNickname() << std::endl;
				std::cout << "Phone Number  : " << arr_contacts[j].getPhone_num() << std::endl;
				std::cout << "Darkest Secret: " << arr_contacts[j].getDarkest_secret() << std::endl;
			}
			j++;
		}
		if (flag != 1)
		{
			std::cout << red << "Index doesn't exist try again!!" << std::endl;
			std::cout << reset;
		}
		else
			break;
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
		fname = arr_contacts[i].getFirst_name();
		arr_contacts[i].check_input(fname);
		lname = arr_contacts[i].getLast_name();
		arr_contacts[i].check_input(lname);
		nname = arr_contacts[i].getNickname();
		arr_contacts[i].check_input(nname);
		std::cout << "|" << std::flush;
		std::cout << std::setw(10) << i << "|" 
					<< std::setw(10) << fname << "|" 
					<< std::setw(10) << lname << "|" 
					<< std::setw(10) << nname << "|" 
					<< std::endl;
		std::cout << "|----------" << "|----------" << "|----------" << "|----------|" << std::endl;
		i++;
	}
	contact_information(index);
}

void	PhoneBook::add_contact(int index)
{
	std::string	name;

	if (std::cin.eof())
		exit(0);
	write_string(" The Information Of The New Contact", green);
	std::cout << reset;
	arr_contacts[index % 8].setFirst_name(name);
	arr_contacts[index % 8].setLast_name(name);
	arr_contacts[index % 8].setNickname(name);
	arr_contacts[index % 8].setPhone_num(name);
	arr_contacts[index % 8].setDarkest_secret(name);
}

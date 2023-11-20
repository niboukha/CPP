/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:06:19 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/20 13:22:48 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	PhoneBook 	phonebook;
	std::string	name;
	int			index;
    int         index_search;
	
	index = 0;
    index_search = 0;
	phonebook.writeString("        Welcome In Your PhoneBook", yellow);
	while (1)
	{
	    phonebook.writeString(" Choose Your Choice : ADD, SEARCH & EXIT", cyan);
		std::cout << reset;
		std::getline(std::cin, name);
		if (phonebook.valideCmd(name, "EXIT"))
			PhoneBook::exitMessage("EXIT");
		if (std::cin.eof())
			PhoneBook::exitMessage("Abborting !!");
        if (name.empty())
            continue;
		if(phonebook.valideCmd(name, "ADD"))
		{
			phonebook.setIndex(index);
			if (!phonebook.addContact(index))
				PhoneBook::exitMessage("Abborting !!");
			index++;
            if (index_search < 8)
                index_search++;
		}
		else if (phonebook.valideCmd(name, "SEARCH"))
			phonebook.search(index_search);
		else
		{
			std::cout << red << "Invalide Commande" << std::endl;
		}
	}
	return (0);
}


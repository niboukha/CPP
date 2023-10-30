/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:06:19 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/30 14:10:30 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	PhoneBook 	contact;
	std::string	name;
	int			index;
    int         index_search;
	
	index = 0;
    index_search = 0;
	contact.write_string("        Welcome In Your PhoneBook", yellow);
	while (1)
	{
	    contact.write_string(" Choose Your Choice : ADD, SEARCH & EXIT", cyan);
		std::cout << reset;
		std::getline(std::cin, name);
		if (contact.valide_cmd(name, "EXIT") || std::cin.eof())
			exit(0);
        if (name.empty())
            continue;
		if(contact.valide_cmd(name, "ADD"))
		{
			contact.setIndex(index);
			contact.add_contact(index);
			index++;
            if (index_search < 8)
                index_search++;
		}
		else if (contact.valide_cmd(name, "SEARCH"))
			contact.search(index_search);
		else
		{
			std::cout << red << "Invalide Commande" << std::endl;
		}
	}
	return (0);
}


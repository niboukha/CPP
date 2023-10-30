/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:01:32 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/30 13:27:11 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "contact.hpp"

//-----color----------

#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define magenta "\033[1;35m"
#define cyan "\033[1;36m"
#define reset "\033[1;0m"


class	PhoneBook
{
	private :
		Contact	arr_contacts[8];
		int		index;

	public :
		void	add_contact(int index);
		void	search(int index);
		bool	valide_cmd(std::string &name, std::string cmd);
		void	write_string(std::string const &name, const char *color);
		int		getIndex();
		void	setIndex(int i);
		void	contact_information(int index);
};

#endif

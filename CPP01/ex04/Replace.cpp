/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:36:18 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/04 16:28:37 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string	Replace::find_in_str(std::string str, std::string s1, std::string s2)
{
	std::size_t	found;
	std::string	sub_string;

	found = str.find(s1);
	if (found == std::string::npos)
		return (str);
	sub_string = str.substr(0, found);
	while (found != std::string::npos)
	{
		str = str.substr(found + s1.length(), str.length());
		found = str.find(s1);
		sub_string += s2;
		sub_string += str.substr(0, found);
	}
	return (sub_string);
}

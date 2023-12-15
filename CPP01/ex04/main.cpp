/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:37:06 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/26 11:12:16 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av)
{
	std::ifstream	myfile;
	std::ofstream	tofile;
	std::string		file, s1, s2, str;
	
	if (ac != 4)
	{
		std::cout << "Invalid input !!" << std::endl;
		return (1);
	}
	s1 = av[2], s2 = av[3], file = av[1];
	if (s1.empty() || s2.empty())
	{
		std::cout << "string should be non empty !!" << std::endl;
		return (1);
	}
	file += ".replace";
	myfile.open(av[1]);
	if (!myfile.is_open())
	{
		std::cout << "Invalid file !!" << std::endl;
		return (1);
	}
	tofile.open(file.c_str());
	if (!tofile.is_open())
	{
		std::cout << "Invalid file !" << std::endl;
		return (1);
	}
	while (std::getline(myfile, str))
	{
		str = Replace::find_in_str(str, s1, s2);
		if (myfile.peek() == EOF)
			tofile << str;
		else
			tofile << str << std::endl;
	}
	myfile.close();
	tofile.close();
	return (0);
}

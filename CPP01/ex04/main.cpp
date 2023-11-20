/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:37:06 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/04 16:26:21 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main()
{
	std::ifstream	myfile;
	std::ofstream	tofile;
	std::string		s1;
	std::string		s2;
	std::string		str;
	
	s1 = "A";
	s2 = "AA";
	myfile.open("myfile", std::ios::in);
	tofile.open("myfile.replace" , std::ios::trunc);
	if (!myfile.is_open() || !tofile.is_open())
		return (1);
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
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:37:06 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/03 17:12:50 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main()
{
	std::ifstream	myfile;
	std::ofstream	tofile;
	std::string	s1;
	std::string	s2;
	
	myfile.open("../cpp_note", std::ios::in);
	tofile.open("../cpp_note4", std::ios::trunc);
	if (!myfile.is_open() || !tofile.is_open())
		return (1);
	while (std::getline(myfile, s1))
	{
		s2 = s1;
		tofile << s2;
	}
	myfile.close();
	tofile.close();
}

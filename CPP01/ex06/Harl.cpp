/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:26:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/08 11:20:13 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\
	I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::complain(std::string level)
{
	std::string				arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::* harl[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int							i;
	
	i = 0;
	while (i < 4)
	{
		if (!level.compare(arr[i]))
			break;
		i++;
	}
	switch (i)
	{
		case 0 :
				(this->*harl[0])();
				std::cout << std::endl;
		case 1 :
				(this->*harl[1])();
				std::cout << std::endl;
		case 2 :
				(this->*harl[2])();
				std::cout << std::endl;
		case 3 :
				(this->*harl[3])();
				std::cout << std::endl;
			break;
		default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break;
	}
}

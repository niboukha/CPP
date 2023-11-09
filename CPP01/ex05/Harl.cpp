/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:35:12 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/08 10:15:11 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
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
	int	i;
	
	void	(Harl::* harl[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	i = 0;
	while (i < 4)
	{
		if (!level.compare(arr[i]))
		{
			(this->*harl[i])();
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << "invalide level!!" << std::endl;
}


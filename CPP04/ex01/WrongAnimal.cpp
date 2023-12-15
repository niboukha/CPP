/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:42:05 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 11:07:37 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "Default constractor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& Wronganimal)
{
	std::cout << "Copy Constractor WrongAnimal" << std::endl;
	this->operator=(Wronganimal);
}

WrongAnimal&   WrongAnimal::operator=(const WrongAnimal& Wronganimal)
{
	std::cout << "Copy assignement WrongAnimal" << std::endl;
	type = Wronganimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor WrongAnimal" << std::endl;
}

void	WrongAnimal::setType(std::string _type)
{
	type = _type;
}

const std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "NO sounds" << std::endl;
}

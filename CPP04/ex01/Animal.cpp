/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:17:55 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/29 13:34:12 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Default constractor Animal" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Copy Constractor Animal" << std::endl;
	this->operator=(animal);
}

Animal&   Animal::operator=(const Animal& animal)
{
	std::cout << "Copy assignement Animal" << std::endl;
	type = animal.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Destructor Animal" << std::endl;
}

void	Animal::setType(std::string _type)
{
	type = _type;
}

const std::string	Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "NO sounds" << std::endl;
}

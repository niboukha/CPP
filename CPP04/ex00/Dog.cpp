/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:44:06 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/29 14:10:23 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default constractor Dog" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Copy Constractor Dog" << std::endl;
	this->operator=(dog);
}

Dog&   Dog::operator=(const Dog& dog)
{
	std::cout << "Copy assignement Dog" << std::endl;
	type = dog.type;
    return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog" << std::endl;
}

void	Dog::makeSound() const
{
    std::cout << "Dog says WooF" << std::endl;
}

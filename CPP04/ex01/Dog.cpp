/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:44:06 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 10:07:03 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) 
{
	std::cout << "Default constractor Dog" << std::endl;
    type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Copy Constractor Dog" << std::endl;
	brain = new Brain();
	this->operator=(dog);
}

Dog&   Dog::operator=(const Dog& dog)
{
	std::cout << "Copy assignement Dog" << std::endl;
	type = dog.type;
	*brain = *(dog.brain);
    return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog" << std::endl;
	delete brain;
}

void	Dog::makeSound() const
{
    std::cout << "Dog says WooF" << std::endl;
}

const std::string&   Dog::getDogIdea(int index) const
{
	return (brain->getBrain(index));
}

void    Dog::setDogIdea(std::string idea, int index)
{
	brain->setBrain(idea, index);
}

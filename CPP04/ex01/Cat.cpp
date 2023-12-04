/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:48:18 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 15:23:38 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) 
{
	std::cout << "Default constractor Cat" << std::endl;
    type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Copy Constractor Cat" << std::endl;
	brain = new Brain();
	this->operator=(cat);
}

Cat&   Cat::operator=(const Cat& cat)
{
	std::cout << "Copy assignement Cat" << std::endl;
	type = cat.type;
	*brain = *(cat.brain);
    return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat" << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
    std::cout << "Cat says MeoW" << std::endl;
}

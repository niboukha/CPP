/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:52:41 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 10:12:13 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constractor Brain" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Copy Constractor Brain" << std::endl;
	this->operator=(brain);
}

Brain&   Brain::operator=(const Brain& brain)
{
	std::cout << "Copy assignement Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
    return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Destructor Brain" << std::endl;
}

const std::string&   Brain::getBrain(int index) const
{
	return (ideas[index]);
}

void    Brain::setBrain(std::string idea, int index)
{
	ideas[index] = idea;
}


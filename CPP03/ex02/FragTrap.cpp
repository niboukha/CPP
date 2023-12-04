/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:14:45 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 09:37:56 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Default FragTrap Constructor called !!" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragtrap)
{
	std::cout << "copy constructor FragTrap called !!" << std::endl;
    this->operator=(fragtrap);
}

FragTrap&   FragTrap::operator=(const FragTrap &fragtrap)
{
    name = fragtrap.name;
	hitPoint = fragtrap.hitPoint;
	energyPoint = fragtrap.energyPoint;
	attackDamage = fragtrap.attackDamage;
	std::cout << "copy assignement FragTrap called !!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametrize Constructor FragTrap called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "High fives !!" << std::endl;
}

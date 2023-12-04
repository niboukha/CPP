/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:03:52 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 09:39:40 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Default ScaveTrap Constructor called !!" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap)
{
	std::cout << "copy constructor ScaveTrap called !!" << std::endl;
	this->operator=(scavtrap);
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout << "copy assignement ScavTrap called !!" << std::endl;
	name = scavtrap.name;
	hitPoint = scavtrap.hitPoint;
	energyPoint = scavtrap.energyPoint;
	attackDamage = scavtrap.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScaveTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
	std::cout << "Constructor ScaveTrap called" << std::endl;	
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

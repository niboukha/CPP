/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:39:16 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 09:40:34 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default DiamondTrap Constructor called !!" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap)
{
	std::cout << "copy constructor DiamondTrap called !!" << std::endl;
	this->operator=(diamondtrap);
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "copy assignement DiamondTrap called !!" << std::endl;
	name = copy.name;
	ClapTrap::name = copy.ClapTrap::name;
	hitPoint = copy.hitPoint;
	energyPoint = copy.energyPoint;
	attackDamage = copy.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) : name(_name)
{
	std::cout << "Constructor DiamondTrap called" << std::endl;
	ClapTrap::name = _name + "_clap_name";
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 30;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << name << ", ClapTrap name : " << ClapTrap::name << std::endl;
}

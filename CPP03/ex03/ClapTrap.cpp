/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:40 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 09:37:08 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
			hitPoint(10),
			energyPoint(10),
			attackDamage(0)
{
	std::cout << "Default Constructor called !!" << std::endl;
}

ClapTrap::ClapTrap(std::string str) :
			name(str),
			hitPoint(10),
			energyPoint(10),
			attackDamage(0)
{
	std::cout << str << " Parameterize Constructor called !!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << name << "copy constructor called !!" << std::endl;
	this->operator=(claptrap);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "copy assignement called !!" << std::endl;
	name = claptrap.name;
	hitPoint = claptrap.hitPoint;
	energyPoint = claptrap.energyPoint;
	attackDamage = claptrap.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor called !!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoint == 0)
	{
		std::cout << "ClapTrap deid !" << std::endl;
		return ;
	}
	if (energyPoint == 0)
	{
		std::cout << "ClapTrap have no energy!" << std::endl;
		return ;
	}
	energyPoint--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "\
		<< attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint > amount)
		hitPoint -= amount;
	else
	{
		hitPoint = 0;
		std::cout << "ClapTrap deid !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " takeDamage of " << amount << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoint == 0)
	{
		std::cout << "ClapTrap deid !" << std::endl;
		return ;
	}
	if (energyPoint == 0)
	{
		std::cout << "ClapTrap have no energy!" << std::endl;
		return ;
	}
	if (hitPoint <= 1000)
		hitPoint += std::min(amount, 1000 - hitPoint);
	energyPoint--;
	std::cout << "ClapTrap " << name << "repairs" << amount << std::endl;
}

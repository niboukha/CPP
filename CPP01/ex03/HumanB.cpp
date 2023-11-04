/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:51:10 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/03 16:20:27 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{}

HumanB::HumanB(std::string name) : hum(name)
{
}

void	HumanB::setWeapon(Weapon &club)
{
	weap = &club;
}


HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (!weap)
		return ;
	std::cout << "attacks with their " << hum << ' ' << weap->getType() << std::endl;
}


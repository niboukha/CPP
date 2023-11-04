/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:11:34 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/03 16:18:39 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name) : type(name)
{
}

Weapon::Weapon(void)
{}

Weapon::~Weapon(void)
{}

const std::string	&Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string name)
{
	type = name;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:42:13 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/03 16:15:08 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon &club) : weap(club)
{
}

HumanA::HumanA(std::string name, Weapon &club) :
	str(name), weap(club)
{
}

void	HumanA::attack()
{
	std::cout << "attacks with their "<< str << ' ' << weap.getType() << std::endl;
}

HumanA::~HumanA()
{
}

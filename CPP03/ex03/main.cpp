/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:44 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 12:25:49 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap    obj("Game");

    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.takeDamage(5);
    obj.attack("aaa");
    obj.highFivesGuys();
    obj.whoAmI();
    return (0);
}

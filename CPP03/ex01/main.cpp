/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:44 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 09:35:52 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap    obj("Game ");

    ScavTrap    c = obj;

    c.takeDamage(100);
    obj.attack("ff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    c.takeDamage(5);
    obj.attack("aaa");
    obj.guardGate();
    return (0);
}

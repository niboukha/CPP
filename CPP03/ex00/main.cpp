/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:44 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 09:36:06 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    obj("game");
    
    obj.attack("ff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.attack("fff");
    obj.beRepaired(10);
    obj.attack("fff");
    obj.takeDamage(5);
    obj.attack("aaa");
    obj.takeDamage(5);
    obj.takeDamage(5);
    obj.takeDamage(5);
    obj.takeDamage(5);
    obj.attack("aaa");
    return (0);
}

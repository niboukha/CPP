/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:44 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 09:35:47 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap    obj("Game ");

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
    obj.takeDamage(5);
    obj.attack("aaa");
    obj.highFivesGuys();
    return (0);
}

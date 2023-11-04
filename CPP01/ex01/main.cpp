/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:25 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/02 11:56:51 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie  *obj = NULL;
    
    obj = zombieHorde(5, "Foo");
    for (int i = 0; i < 5; i++)
        obj->announce();
    delete [] obj;
    return (0);
}

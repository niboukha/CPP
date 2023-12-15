/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:49:39 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 11:25:57 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void funv()
{
    IMateriaSource* src = new MateriaSource();
    
    AMateria    *IceAD = new Ice();
    AMateria    *CureAD = new Cure();
    
    src->learnMateria(IceAD);
    src->learnMateria(CureAD);
    
    delete IceAD;
    delete CureAD;

    ICharacter* me = new Character("me");

    IceAD = src->createMateria("ice");
    me->equip(IceAD);
    me->equip(IceAD);
    me->unequip(0);
    CureAD = src->createMateria("cure");
    me->equip(CureAD);
    me->equip(CureAD);
    me->equip(CureAD);
    me->equip(CureAD);
    me->equip(CureAD);
    me->equip(CureAD);
    me->equip(CureAD);
    me->equip(CureAD);
    me->equip(CureAD);
    me->equip(CureAD);
    // me->unequip(0);
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    
    delete IceAD;
    delete CureAD;
    delete bob;
    delete me;
    delete src;
}

int main()
{
    funv();
    // system("leaks ex03");
    return 0;
}

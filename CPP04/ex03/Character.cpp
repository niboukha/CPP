/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:57 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 17:11:29 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::GbColl*	Character::GbColl::front = NULL;

Character::Character() : name("character ")
{
	// std::cout << "Default constructor Character" << std::endl;
    for (int i = 0; i < 4; i++)
        slots[i] = NULL;
}

Character::Character(Character& Character) : name("copy name")
{
	// std::cout << "Copy Constructor Character" << std::endl;
    this->operator=(Character);
}

Character&   Character::operator=(const Character& character)
{
    if (this == &character)
        return (*this);
	// std::cout << "Copy assignement Character" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete slots[i];
        slots[i] = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        if (character.slots[i])
            slots[i] = character.slots[i]->clone();
    }
    return (*this);
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
        delete slots[i];
    GbColl::freeAll(&GbColl::front);
	// std::cout << "Destructor Character" << std::endl;
}

Character::Character(std::string const &  _name) : name(_name)
{
	// std::cout << "Paramitrize Constructor Character" << std::endl;
    for (int i = 0; i < 4; i++)
        slots[i] = NULL;
}

std::string const& Character::getName() const
{
    return (name);
}

void	Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
        if (!slots[i])
        {
            slots[i] = m->clone();
            break;
        }
}

void	Character::unequip(int idx)
{
    if (slots[idx])
        GbColl::addFront(&GbColl::front, new GbColl(slots[idx]));
    slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
    if (slots[idx])
        slots[idx]->use(target);
}

Character::GbColl::GbColl(AMateria *value) : val(value), next(NULL)
{
}

Character::GbColl::GbColl()
{ 
}

Character::GbColl::GbColl(const Character::GbColl& gbcoll)
{
    (void)gbcoll;
}

Character::GbColl&  Character::GbColl::operator=(const Character::GbColl& gbcoll)
{
    (void)gbcoll;
    return (*this);
}

Character::GbColl::~GbColl()
{
}

void	Character::GbColl::addFront(GbColl **head, GbColl *newVal)
{
    if (!*head)
        *head = newVal;
    else
    {
        newVal->next = *head;
        *head = newVal;
    }
}

void	Character::GbColl::freeAll(GbColl **head)
{
    GbColl  *tmp;

    while (*head)
    {
        delete (*head)->val;
        tmp = *head;
        *head = (*head)->next;
        delete tmp;
    }
}



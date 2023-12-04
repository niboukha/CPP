/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:13:38 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 15:52:54 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "Default constructor MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++)
        maSource[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource& materiaSource)
{
    // std::cout << "Copy Constructor MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++)
        maSource[i] = NULL;
    this->operator=(materiaSource);
}

MateriaSource&   MateriaSource::operator=(const MateriaSource& materiaSource)
{
    // std::cout << "Copy assignement materiaSource" << std::endl;
    for (int i = 0; i < 4; i++)
        delete maSource[i];
    for (int i = 0; i < 4; i++)
        maSource[i] = materiaSource.maSource[i]->clone();   
    return (*this);
} 

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
        delete maSource[i];
    // std::cout << "Destructor MateriaSource" << std::endl;
}

void		MateriaSource::learnMateria(AMateria* materia)
{
    for(int i = 0; i < 4; i++)
        if (!maSource[i])
        {
            maSource[i] = materia->clone();
            break;
        }
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < 4; i++)
    if (maSource[i] && maSource[i]->getType() == type)
        return(maSource[i]->clone());
    return (0);
}

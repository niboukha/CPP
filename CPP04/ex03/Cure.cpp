/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:49:22 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/30 18:50:46 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Default constructor Cure" << std::endl;
}

Cure::Cure(Cure& cure)
{
	// std::cout << "Copy Constructor Cure" << std::endl;
    this->operator=(cure);
}

Cure&   Cure::operator=(const Cure& cure)
{
    (void)cure;
	// std::cout << "Copy assignement Cure" << std::endl;
    return (*this);
}

Cure::~Cure()
{
	// std::cout << "Destructor Cure" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria	*cure = new Cure;
	*cure = *this; //why and how
	return (cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}


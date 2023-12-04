/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:49:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 15:51:24 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Default constructor Ice" << std::endl;
}

Ice::Ice(Ice& ice)
{
	// std::cout << "Copy Constructor Ice" << std::endl;
    this->operator=(ice);
}

Ice&   Ice::operator=(const Ice& ice)
{
    (void)ice;
	// std::cout << "Copy assignement Ice" << std::endl;
    return (*this);
}

Ice::~Ice()
{
	// std::cout << "Destructor Ice" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria	*ice = new Ice;

	*ice = *this;
	return (ice);
}

void    Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; //get
}



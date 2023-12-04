/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:49:29 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/30 18:43:38 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	// std::cout << "Default constructor AMateria" << std::endl;
}

AMateria::AMateria(AMateria& amateria) : _type("default")
{
	// std::cout << "Copy Constructor AMateria" << std::endl;
    this->operator=(amateria);
}

AMateria&   AMateria::operator=(const AMateria& amateria)
{
    (void)amateria;
	// std::cout << "Copy assignement AMateria" << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
	// std::cout << "Destructor AMateria" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "Paramitrize Constructor AMateria" << std::endl;
}

std::string const& AMateria::getType() const
{
    return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}


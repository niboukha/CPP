/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:40:11 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 11:07:52 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Default constractor WrongCat" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wrongcat)
{
	std::cout << "Copy Constractor WrongCat" << std::endl;
	this->operator=(wrongcat);
}

WrongCat&   WrongCat::operator=(const WrongCat& wrongcat)
{
	std::cout << "Copy assignement WrongCat" << std::endl;
	type = wrongcat.type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor WrongCat" << std::endl;
}

void	WrongCat::makeSound() const
{
    std::cout << "WrongCat says MeoW" << std::endl;
}

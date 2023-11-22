/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:12:51 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/21 17:40:11 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::numFracBits = 8;

Fixed::Fixed(void) : fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl; 
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	fixedValue = fixed.fixedValue;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
    //current obj const
    
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
    fixedValue = raw;
}

Fixed::Fixed(const int value) : fixedValue(value << numFracBits)
{
	std::cout << "Int constructor called" << std::endl;	
}

Fixed::Fixed(const float value) : fixedValue(std::roundf(value * (1 << numFracBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	float	f;
	
	f = (1.0 * fixedValue) / (1 << numFracBits);
	return (f);
}

int	Fixed::toInt(void) const
{
	int	f;
	
	f = fixedValue >> numFracBits;
	return (f);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return	os;
}

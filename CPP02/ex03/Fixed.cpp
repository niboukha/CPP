/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:54:00 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/27 12:53:11 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int   Fixed::numFracBits = 8;

Fixed::Fixed(void) : fixedValue(0)
{
	// std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->operator=(copy);
}


Fixed&	Fixed::operator=(const Fixed& fixed)
{
	fixedValue = fixed.fixedValue;
	return (*this);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixedValue(value << numFracBits)
{
	// std::cout << "Int constructor called" << std::endl;	
}

Fixed::Fixed(const float value) : fixedValue(std::roundf(value * (1 << numFracBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	float	f;

	f = (1.0 * fixedValue) / (1 << numFracBits);
	return (f);
}

int	Fixed::toInt(void) const
{
	float	f;

	f = (1.0 * fixedValue) / (1 << numFracBits);
	return (std::roundf(f));
}

int	Fixed::getRawBits(void) const
{
    return (fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
    fixedValue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return	os;
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (fixedValue > fixed.fixedValue);
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (fixedValue < fixed.fixedValue);
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (fixedValue >= fixed.fixedValue);
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (fixedValue <= fixed.fixedValue);
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (fixedValue == fixed.fixedValue);
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (fixedValue != fixed.fixedValue);
}

Fixed	Fixed::operator+(Fixed const& fixed)  const
{
	Fixed	obj;

	obj.fixedValue = fixedValue + fixed.fixedValue;
	return (obj);
}

Fixed	Fixed::operator-(Fixed const& fixed) const
{
	Fixed	obj;

	obj.fixedValue = fixedValue - fixed.fixedValue;
	return (obj);
}

Fixed	Fixed::operator*(Fixed const& fixed) const
{
	Fixed	obj;

	obj.fixedValue = std::roundf((fixedValue * fixed.fixedValue * 1.0) / (1 << numFracBits));
	return (obj);
}

Fixed	Fixed::operator/(Fixed const& fixed) const
{
	Fixed	obj;

	obj.fixedValue = std::roundf((fixedValue * 1.0 * (1 << numFracBits)) / fixed.fixedValue);
	return (obj);
}

Fixed&		Fixed::operator++()
{
	fixedValue++;
	return (*this);
}

Fixed&		Fixed::operator--()
{
	fixedValue--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	Fixed	obj;
	
	obj = *this;
	--fixedValue;
	return (obj);
}

Fixed		Fixed::operator++(int)
{
	Fixed	obj;
	
	obj = *this;
	++fixedValue;
	return (obj);
}

Fixed&	Fixed::min(Fixed& fstFixed, Fixed& secFixed)
{
	return ((fstFixed > secFixed) ? secFixed : fstFixed);
}

const Fixed&	Fixed::min(const Fixed& fstFixed, const Fixed& secFixed)
{
	return ((fstFixed > secFixed) ? secFixed : fstFixed);
}

Fixed&	Fixed::max(Fixed& fstFixed, Fixed& secFixed)
{
	return ((fstFixed < secFixed) ? secFixed : fstFixed);
}

const Fixed&	Fixed::max(const Fixed& fstFixed, const Fixed& secFixed)
{
	return ((fstFixed < secFixed) ? secFixed : fstFixed);
}

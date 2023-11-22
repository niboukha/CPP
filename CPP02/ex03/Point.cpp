/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:37:41 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/21 17:13:13 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float a, const float b) : x(a), y(b)
{
}

Point::~Point(void)
{
}

Point::Point(const Point& copy) : x(copy.x), y(copy.y)
{
}

Point&  Point::operator=(const Point& point)
{
	(void)point;
	return (*this);
}

const Fixed	Point::getX(void) const
{
	return(x);
}

const Fixed	Point::getY(void) const
{
	return (y);	
}


Fixed	Point::areaTriangle(Point const a, Point const b, Point const c)
{
	Fixed	area = (a.getX() * (b.getY() - c.getY())
				+ b.getX() * (c.getY() - a.getY())
				+ c.getX() * (a.getY() - b.getY())) / Fixed(2);
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area);
}

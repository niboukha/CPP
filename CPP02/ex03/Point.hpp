/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:08:57 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/25 18:19:03 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include "Fixed.hpp"

class Point
{
	private :
		const Fixed x;
		const Fixed y;
	
	public :
		Point(void);
		Point(const float a, const float b);
		~Point(void);
		Point(const Point& copy);
		
		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
		
		Point&  operator=(const Point& point);
		
		static Fixed	areaTriangle(Point const a, Point const b, Point const c);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif

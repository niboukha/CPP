/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:11:28 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/21 17:27:11 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	trgA;
	Fixed	trgB;
	Fixed	trgC;
	Fixed	trgP;
	
	trgA = Point::areaTriangle(a, b, c);
	trgB = Point::areaTriangle(a, b, point);
	trgC = Point::areaTriangle(a, c, point);
	trgP = Point::areaTriangle(b, c, point);
	
	std::cout << trgA << " " <<trgB << " " <<trgC << " "  << trgP << std::endl;
	if (trgA == (trgB + trgC + trgP) and trgA != Fixed(0)
		and trgB != Fixed(0) and trgC != Fixed(0) and trgP != Fixed(0))
		return (true);
	return (false);
}

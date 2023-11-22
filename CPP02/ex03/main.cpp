/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:59:22 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/21 17:28:24 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(0,0);
    Point b(6,8);
    Point c(12,0);
    Point p(0 , 0);
    
    std::cout << "aa " << Point::areaTriangle(a, b, c) << std::endl;
    std::cout << bsp(a, b, c, p) << std::endl;
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:30:33 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/22 11:17:44 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        Span                sp = Span(100007);
        std::vector<int>    vect;
        
        sp.addNumber(30);
        sp.addNumber(333);
        sp.addNumber(17);
        sp.addNumber(20);
        sp.addNumber(11);
        sp.addNumber(INT_MAX);
        sp.addNumber(INT_MIN);

        for (size_t i = 334; i < 100333; i++)
            vect.push_back(i);
            
        sp.fillSpan(vect.begin(), vect.end());
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan()  << std::endl;
        
        const Span  spa(sp);
        
        std::cout << spa.shortestSpan() << std::endl;
        std::cout << spa.longestSpan()  << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:14:19 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/11 10:38:16 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  buro("niserin", 147);
        std::cout << buro << std::endl;
        buro.low(buro);
        std::cout << buro << std::endl;
        buro.low(buro);
        std::cout << buro << std::endl;
        buro.low(buro);
        std::cout << buro << std::endl;
        buro.low(buro);
        std::cout << buro << std::endl;
        buro.high(buro);
        std::cout << buro << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exeption: " << e.what() << std::endl;
    }
    return(0);
}

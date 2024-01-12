/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:49:22 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/18 11:46:45 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int ac, char **av )
{
    std::string input;
    
    if (ac > 1)
    {
        input += av[1];
        ScalarConverter::convert(input);
    }
    return (0);
}

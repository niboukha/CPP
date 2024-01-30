/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:37:29 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/09 12:19:33 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw BitcoinExchange::ArgumentException();

        std::ifstream   file(av[1]);
        try
        {
        
            if (!file.is_open())
                throw BitcoinExchange::fileException();

            std::string     input;
            BitcoinExchange obj;
        
            std::getline (file, input);
            obj.parseFirstLine(input);
            while (std::getline (file, input))
                obj.displayResult(input);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}

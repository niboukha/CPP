/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:38:48 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/20 16:05:34 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::vector<std::string>    s;
    int                         i;
    
    try
    {
        if (ac > 1)
        {
            i = 1;
            for (; av[i]; i++)
                s.push_back(av[i]);
            PmergeMe    obj(s);
            obj.mergeInsertionSort();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}

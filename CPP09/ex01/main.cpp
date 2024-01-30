/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:40:47 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/20 12:53:25 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    std::string input;
    std::string arg;
    std::stack<int> stack;

    try
    {        
        if (ac == 2)
        {
            arg += av[1];
            std::istringstream s(arg);
            while (s >> input)
                RPN::rPolishNotation(stack, input);
            if (!stack.empty() and stack.size() == 1)
                std::cout << stack.top() << "\n";
            else
                throw RPN::InvalidInput();
        }
        else
            throw RPN::InvalidInput();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

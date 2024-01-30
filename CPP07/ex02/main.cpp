/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:01:40 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/14 11:05:38 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 7

int main(int, char**)
{
    {
        Array<int>  numbers(MAX_VAL);
        int*        mirror = new int[MAX_VAL];

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = 5;
            mirror[i] = 5;
        }
        
        const Array<int>  num(numbers);
        
        std::cout << "const array : " << "\n";
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << num[i] << " ";
        }
        std::cout << std::endl;
        
        const Array<int>    tmp = numbers;
        Array<int>          test(tmp);
        
        std::cout << "copy constructor :" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << tmp[i] << " ";
        std::cout << std::endl;

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand() % MAX_VAL;
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
        
        Array<int>          assign;

        std::cout << assign.size() << "\n";
        assign = numbers;
        
        std::cout << "copy assignement :" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << assign[i] << " ";
        std::cout << std::endl;
        
        delete [] mirror;
    }
    
    /////////////////////////////////////
    
    {
        Array<char> str(7);
        std::string s = "helloni";
        
        for (size_t i = 0; i < str.size(); i++)
            str[i] = s[i];
        
        const Array<char> tmp = str;
        Array<char> test(tmp);
        
        std::cout << "copy constructor :" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << tmp[i] << " ";
        std::cout << std::endl;
        
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (s[i] != str[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        
        try
        {
            str[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        try
        {
            str[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            str[i] = rand() % 26 + 'a';
            std::cout << str[i] << " ";
        }
        std::cout << std::endl;
        
    }
    
    return 0;
}


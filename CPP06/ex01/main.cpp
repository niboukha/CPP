/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:12:20 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/12 16:18:14 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data    *ptr;
    Data    *new_ptr = NULL;

    ptr = new Data;
    
    ptr->i = 10;
    ptr->c = 'a';
    ptr->in = &ptr->i;

    std::cout << ptr->i << " " << ptr->c << " " << *(ptr->in) << std::endl;

    uintptr_t a = Serializer::serialize(ptr);
    
    std::cout << ptr->i << " " << ptr->c << " " << *(ptr->in) << std::endl;
    
    new_ptr = Serializer::deserialize(a);

    std::cout << new_ptr->i << " " << new_ptr->c << " " << *(new_ptr->in) << std::endl;
    
    delete ptr;
    
    return (0);
}

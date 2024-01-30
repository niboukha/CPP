/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:12:27 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/13 12:12:21 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>

void    swap(T &a, T &b)
{
    T   tmp;
    
    tmp = a;
    a   = b;
    b   = tmp;
} 

template <typename T>

const T&   min(const T& a, const T& b)
{
    return ((b <= a) ? b : a);
}

template <typename T>

const T&   max(const T& a, const T& b)
{
    return ((b >= a) ? b : a);
}

#endif

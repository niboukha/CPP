/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:43:41 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/13 15:30:00 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib> 
#include <time.h>

template <typename T>

class Array
{
    private :
    
        unsigned int    n;
        T               *arr;
        
    public :
    
        Array () : n(0) { arr = new T[0]; }
        
        Array ( unsigned int _n ) : n(_n) { arr = new T[n]; }
        
        Array ( const Array& copy )
        {
            n   = copy.n;
            arr = new T[n];

            for (size_t i = 0; i < n; i++)
                arr[i] = copy.arr[i];
        }

		Array& operator=( const Array& assign )
        {
            n   = assign.n;

            if (this != &assign)
            {
                delete [] arr;
                arr = new T[n];
                
                for (size_t i = 0; i < n; i++)
                    arr[i] = assign.arr[i];
            }
            return (*this);
        }
        
        ~Array() { delete [] arr; }

        class	IndexException : public std::exception
        {
            public :
                const char	*what() const throw()
                {
                    return ( "Invalid Index!!" );
                }
        };

        T& operator[] (int index)
        {
            if (index < 0 || static_cast<std::size_t>(index) >= n)
                throw   IndexException();
            return ( arr[index] );
        }

        const T& operator[] (int index) const
        {
            if (index < 0 || static_cast<std::size_t>(index) >= n)
                throw   IndexException();
            return ( arr[index] );
        }

        const unsigned int&    size() const { return (n); }	
};


#endif

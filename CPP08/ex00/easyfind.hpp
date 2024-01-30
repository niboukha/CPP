/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:54:59 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/22 10:57:38 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class	IndexException : public std::exception
{
    public :
        const char	*what() const throw()
        {
            return ( "No occurrence is found." );
        }
};

template < typename T >

int  easyfind(const T &vect, int n )
{
    typename T::const_iterator  it;

    it = std::find (vect.begin(), vect.end(), n);
    if (it != vect.end())
        return (it - vect.begin());
    throw IndexException();
}

#endif

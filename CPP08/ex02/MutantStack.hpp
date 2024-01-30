/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:21:42 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/14 13:11:59 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <vector>

template < typename T, typename C = std::deque<T> >

class MutantStack : public std::stack<T, C>
{
    public :
        MutantStack()
        { 
        }
        
		MutantStack ( const MutantStack& copy )
        {
            this->operator=(copy);    
        }
        
        ~MutantStack()
        {
        }

		MutantStack&    operator=( const MutantStack& assign )
        {
            this->c = assign.c;
            return (*this);
        }
        
        typedef typename C::iterator iterator;

        iterator begin()
        {
            return (this->c.begin());
        }
        iterator end()
        {
            return (this->c.end());
        }
};

#endif

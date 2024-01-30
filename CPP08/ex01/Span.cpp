/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:20:20 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/22 11:21:27 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int n ) : _N( n )
{
    sp.reserve(n);
}

Span::Span ( const Span& copy )
{
    _N = copy._N;
    sp = copy.sp;
}

Span::~Span()
{

}

Span& Span::operator=( const Span& assign )
{
    _N = assign._N;
    sp = assign.sp;
    return (*this);
}

int& Span::operator[] (int index)
{
    if (index < 0 || static_cast<std::size_t>(index) >= _N)
        throw   IndexException();
    return (sp[index]);
}

const int& Span::operator[] (int index) const
{
    if (index < 0 || static_cast<std::size_t>(index) >= _N)
        throw   IndexException();
    return (sp[index]);
}

const char*	Span::IndexException::what() const throw()
{
	return ("Invalid Index.");
}

const char*	Span::AddException::what() const throw()
{
	return ("There are no space for the added elements.");
}

const char*	Span::SpanException::what() const throw()
{
	return ("No span can be found.");
}

void	Span::addNumber(unsigned int num)
{
    if (sp.size() < _N)
        sp.push_back(num);
    else
        throw AddException();
}

long	Span::shortestSpan() const
{
    std::vector<int>    spCopy;
    long                 shortest;
       
    spCopy   = sp;
    shortest = LONG_MAX;

    if (sp.empty() || sp.size() == 1)
        throw SpanException();
        
    std::sort (spCopy.begin(), spCopy.end());
    
    for (std::vector<int>::const_iterator i = spCopy.begin(), j = i + 1; j != spCopy.end(); i = j, j++)
        shortest = std::min(shortest, abs(static_cast<long>(*i) - *j));

    return (shortest);
}

long	Span::longestSpan() const
{
    std::vector<int>    spCopy;
    long                 longest;
    
    spCopy  = sp;
    longest = 0;
    
    if (sp.empty() || sp.size() == 1)
        throw SpanException();
        
    std::sort (spCopy.begin(), spCopy.end());

    longest = static_cast<long>(spCopy.back()) - spCopy.front();
    
    return (longest);
}

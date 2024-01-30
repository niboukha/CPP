/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:58:31 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/22 11:03:39 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits.h>

class   Span
{
	private :
	
		unsigned int		_N;
		std::vector<int>	sp;

	public :

		Span ();
		Span ( unsigned int n );
		Span ( const Span& copy );
		~Span();
		
		Span&			operator=( const Span& assign );
		
		int&			operator[] ( int index );
		const  int&		operator[] ( int index ) const;
		
		void	addNumber(unsigned int num);
		long		shortestSpan() const;
		long		longestSpan() const;
		
		template <typename T>
		
		void	fillSpan(T begin, T end)
		{
			if (sp.size() + (end - begin) <= _N)
				sp.insert(sp.end(), begin, end);
			else
       			throw AddException();
		}
		
		class	IndexException : public std::exception
		{
			public :
				const char	*what() const throw();
		};
		
		class	AddException : public std::exception
		{
			public :
				const char	*what() const throw();
		};
		
		class	SpanException : public std::exception
		{
			public :
				const char	*what() const throw();
		};
};

#endif

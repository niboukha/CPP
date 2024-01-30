/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:35:47 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/14 11:19:44 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
	private:
		int _n;
		
	public:
		Awesome( void ) : _n( 42 )
		{
			return;
		}
		int get( void ) const
		{
			return this->_n;
		}
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >

void print( T &x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, func<const int> );
  iter( tab2, 5, print< const Awesome> );

  return 0;
}
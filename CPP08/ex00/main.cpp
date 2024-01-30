/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:16:27 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/22 10:58:01 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
    try
    {
        std::vector< int >  v1;
        
        v1.push_back( 10 );
        v1.push_back( 20 );
        v1.push_back( 30 );
        v1.push_back( 40 );
        v1.push_back( 50 );
        v1.push_back( 60 );
            
        std::cout << easyfind( v1, 60 ) << std::endl;
        std::cout << easyfind( v1, 30 ) << std::endl;
    
        const std::vector< int >  v2(v1);
        std::cout << easyfind( v2, 6 ) << std::endl;
    }
    catch ( const std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);

    
}

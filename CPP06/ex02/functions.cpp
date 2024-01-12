/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:36:35 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/10 21:59:37 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Base*	generate( void )
{
    int i;
    
    srand(time(NULL));
    i = (rand() % 3) + 1;
    if (i == 1)
        return (new A());
    else if (i == 2)
        return (new B());
    return (new C());
}

void	identify( Base* p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "The actual type of pbject pointed to by p: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The actual type of pbject pointed to by p: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The actual type of pbject pointed to by p: C" << std::endl;
    else
        std::cout << "It's not Neither of the classes A, B and C" << std::endl;
}

void	identify( Base& p )
{
	try
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "The actual type of the object pointed to by p: A" << std::endl;
        return ;
	}
    catch (std::bad_cast&)
    {
    }
    try
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "The actual type of the object pointed to by p: B" << std::endl;
        return ;
	}
    catch (std::bad_cast&)
    {
    }
    try
	{
        (void)dynamic_cast<C&>(p);
        std::cout << "The actual type of the object pointed to by p: C" << std::endl;
        return ;
	}
    catch (std::bad_cast&)
    {
    }
    std::cout << "It's not Neither of the classes A, B and C" << std::endl;
}

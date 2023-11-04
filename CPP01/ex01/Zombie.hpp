/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:06:57 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/02 11:57:08 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private :
		std::string	name;
	
	public :
		Zombie(std::string zombie);
		Zombie(void);
		~Zombie(void);
		
		void		announce(void);
};

Zombie*	zombieHorde( int N, std::string name );

#endif

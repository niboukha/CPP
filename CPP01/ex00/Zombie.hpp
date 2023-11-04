/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:14 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/02 10:35:26 by niboukha         ###   ########.fr       */
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
		~Zombie();
		
		void		announce(void);
};

void		randomChump( std::string name );
Zombie*		newZombie( std::string name );

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:42 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 11:13:33 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CLAPTRAP_HPP
#define  CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected :
		std::string		name;
		unsigned int 	hitPoint;
		unsigned int 	energyPoint;
		unsigned int	attackDamage;
		
	public :
		ClapTrap(void);
		ClapTrap(std::string str);
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap& operator=(const ClapTrap& claptrap);
		~ClapTrap(void);
		
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif

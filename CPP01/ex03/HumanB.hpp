/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:38:15 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/03 16:14:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private :
		std::string	hum;
		Weapon		*weap;

	public :
		HumanB(std::string name);
		HumanB();
		~HumanB(void);

		void	setWeapon(Weapon &club);
		void	attack(void);
};

#endif

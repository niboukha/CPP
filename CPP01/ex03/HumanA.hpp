/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:58:14 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/03 16:15:22 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private :
		std::string	str;
		Weapon		&weap;

	public :
		HumanA(Weapon &club);
		HumanA(std::string name, Weapon &club);
		~HumanA(void);
		
		void	attack(void);
};

#endif

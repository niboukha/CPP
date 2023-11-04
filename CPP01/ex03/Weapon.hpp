/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:11:38 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/02 15:42:26 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon
{
	private :
		std::string	type;

	public :
		Weapon(std::string	name);
		Weapon(void);
		~Weapon(void);
		const std::string	&getType() const;
		void				setType(std::string name);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:09:10 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 10:25:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected :
		std::string type;
		
	public :
		Animal(void);
		Animal(const Animal& animal);
		Animal&   operator=(const Animal& animal);
		virtual ~Animal(void);

		void	setType(std::string _type);
		const std::string	getType(void) const;
		
		virtual void	makeSound() const = 0;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:14:09 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 15:19:34 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class   Dog : public Animal
{
	public :
		Dog(void);
		Dog(const Dog& Dog);
		Dog&   operator=(const Dog& Dog);
		~Dog(void);
		
		virtual void	makeSound() const;
};

#endif

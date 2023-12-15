/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:41:53 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/29 14:10:43 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongANIMAL_HPP
#define WrongANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected :
		std::string type;
		
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& Wronganimal);
		WrongAnimal&   operator=(const WrongAnimal& Wronganimal);
		~WrongAnimal(void);

		void	setType(std::string _type);
		const std::string	getType(void) const;
		
		void	makeSound() const;
};

#endif

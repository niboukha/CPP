/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:39:08 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 15:18:41 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal
{
	public :
		WrongCat(void);
		WrongCat(const WrongCat& WrongCat);
		WrongCat&   operator=(const WrongCat& WrongCat);
		~WrongCat(void);
		
		void	makeSound() const;
};

#endif

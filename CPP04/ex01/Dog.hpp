/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:14:09 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 10:04:43 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Dog : public Animal
{
	private :
        Brain   *brain;
    
	public :
		Dog(void);
		Dog(const Dog& Dog);
		Dog&   operator=(const Dog& Dog);
		virtual ~Dog(void);
		
		virtual void	makeSound() const;

		const std::string&   getDogIdea(int index) const;
        void    setDogIdea(std::string idea, int index);
		
};

#endif
